#include "PrintFileCommand.hpp"
#include <fstream>

// Класс PrintFileCommand (команда вывода в файл)
PrintFileCommand::PrintFileCommand(const std::string& filename, const std::string& message)
    : filename(filename), message(message) {}

void PrintFileCommand::execute() {
    std::ofstream file(filename, std::ios::app); // Открытие файла в режиме добавления
    if (file.is_open()) {
        file << message << std::endl; // Запись сообщения в файл
        file.close(); // Закрытие файла
    }
}

