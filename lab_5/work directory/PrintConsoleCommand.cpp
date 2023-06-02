#include "PrintConsoleCommand.hpp"
#include <iostream>

// Класс PrintConsoleCommand (команда вывода в консоль)
PrintConsoleCommand::PrintConsoleCommand(const std::string& message)
    : message(message) {}

void PrintConsoleCommand::execute() {
    std::cout << message << std::endl; // Вывод сообщения в консоль
}

