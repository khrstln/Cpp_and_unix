#include "Utils.hpp"

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
        float num1, num2;
        iss >> num1 >> num2;
        std::string line = commandName + " " + std::to_string(num1) + " " + std::to_string(num2);
        commands.push_back(parseArithmeticOperation(line));
    }

    return commands;
}

