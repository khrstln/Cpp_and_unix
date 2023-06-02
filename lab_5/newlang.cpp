#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include <sstream>

// Базовый класс Command (команда)
class Command {
public:
    virtual void execute() = 0; // Виртуальная функция для выполнения команды
};

// Функция executeCommands для последовательного выполнения команд
void executeCommands(const std::vector<Command*>& commands) {
    for (auto command : commands) {
        command->execute(); // Выполнение команды
    }
}

// Функция executeCommandSets для параллельного исполнения наборов команд
void executeCommandSets(const std::vector<std::vector<Command*>>& commandSets) {
    std::vector<std::thread> threads;
    int threadIndex = 1;

    for (const auto& commandSet : commandSets) {
        threads.emplace_back([commandSet, threadIndex]() {
            std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
            std::cout << "Thread " << threadIndex << " started." << std::endl;

            executeCommands(commandSet); // Выполнение команд набора

            std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();
            std::chrono::duration<double> duration = endTime - startTime;
            std::cout << "Thread " << threadIndex << " finished. Execution time: " << duration.count() << "s" << std::endl;
        });

        ++threadIndex;
    }

    // Дождитесь завершения всех потоков
    for (auto& thread : threads) {
        thread.join();
    }
}

// Класс LoopCommand (команда цикла)
class LoopCommand : public Command {
private:
    int count; // Количество итераций цикла
    std::vector<Command*> commands; // Вложенные команды цикла

public:
    LoopCommand(int count, const std::vector<Command*>& commands)
        : count(count), commands(commands) {}

    void execute() override {
        std::vector<std::vector<Command*>> commandSets(count, commands);
        executeCommandSets(commandSets);
    }
};

// Класс PrintConsoleCommand (команда вывода в консоль)
class PrintConsoleCommand : public Command {
private:
    std::string message; // Сообщение для вывода

public:
    PrintConsoleCommand(const std::string& message)
        : message(message) {}

    void execute() override {
        std::cout << message << std::endl; // Вывод сообщения в консоль
    }
};

// Класс PrintFileCommand (команда вывода в файл)
class PrintFileCommand : public Command {
private:
    std::string filename; // Имя файла
    std::string message; // Сообщение для вывода

public:
    PrintFileCommand(const std::string& filename, const std::string& message)
        : filename(filename), message(message) {}

    void execute() override {
        std::ofstream file(filename, std::ios::app); // Открытие файла в режиме добавления
        if (file.is_open()) {
            file << message << std::endl; // Запись сообщения в файл
            file.close(); // Закрытие файла
        }
    }
};

// Класс ArithmeticOperationCommand (команда арифметической операции)
class ArithmeticOperationCommand : public Command {
private:
    char operator_; // Оператор (+, -, *, /)
    float operand1; // Первый операнд
    float operand2; // Второй операнд

public:
    ArithmeticOperationCommand(char op, float operand1, float operand2)
        : operator_(op), operand1(operand1), operand2(operand2) {}

    void execute() override {
        float result;
        switch (operator_) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            default:
                result = 0.0f;
                break;
        }

        std::cout << "Result: " << result << std::endl; // Вывод результата арифметической операции
    }
};



// Функция parseArithmeticOperation для разбора строки арифметической операции
ArithmeticOperationCommand* parseArithmeticOperation(const std::string& line) {
    std::istringstream iss(line);
    std::string operation, operand1Str, operand2Str;
    iss >> operation >> operand1Str >> operand2Str;

    char operator_ = operation[0];
    float operand1 = std::stof(operand1Str);
    float operand2 = std::stof(operand2Str);

    return new ArithmeticOperationCommand(operator_, operand1, operand2);
}

// Функция processCommandString для обработки строки команд
std::vector<Command*> processCommandString(const std::string& commandString) {
    std::vector<Command*> commands;
    std::istringstream iss(commandString);
    std::string commandName;

    iss >> commandName;

    if (commandName == "LOOP") {
        int count;
        iss >> count;

        std::vector<Command*> loopCommands;
        std::string command;
        while (iss >> command && command != "ENDLOOP") {
            if (command == "PRINT_CONSOLE") {
                std::string message;
                iss >> message;
                loopCommands.push_back(new PrintConsoleCommand(message));
            } else if (command == "PRINT_FILE") {
                std::string filename, message;
                iss >> filename;
                iss >> message;
                loopCommands.push_back(new PrintFileCommand(filename, message));
            } else if (command == "+" || command == "-" || command == "*" || command == "/") {
                int num1, num2;
                iss >> num1 >> num2;
                std::string line = command + " " + std::to_string(num1) + " " + std::to_string(num2);
                loopCommands.push_back(parseArithmeticOperation(line)); 
            }
        }

        commands.push_back(new LoopCommand(count, loopCommands));
    } else if (commandName == "PRINT_CONSOLE") {
        std::string message;
        std::getline(iss >> std::ws, message);
        commands.push_back(new PrintConsoleCommand(message));
    } else if (commandName == "PRINT_FILE") {
        std::string filename, message;
        iss >> filename;
        std::getline(iss >> std::ws, message);
        commands.push_back(new PrintFileCommand(filename, message));
    } else if (commandName == "+" || commandName == "-" || commandName == "*" || commandName == "/") {
        commands.push_back(parseArithmeticOperation(commandString));
    }

    return commands;
}

int main() {
    std::vector<std::vector<Command*>> commandSets;
    std::string commandString;

    // Чтение ввода команд
    while (std::getline(std::cin, commandString)) {
        if (commandString.empty()) {
            break; // Окончание ввода команд
        }

        std::vector<Command*> commands = processCommandString(commandString);
        commandSets.push_back(commands);
    }

    // Параллельное выполнение наборов команд
    executeCommandSets(commandSets);

    return 0;
}