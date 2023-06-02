#ifndef PRINT_CONSOLE_COMMAND_HPP
#define PRINT_CONSOLE_COMMAND_HPP

#include <string>
#include "Command.hpp"

// Класс PrintConsoleCommand (команда вывода в консоль)
class PrintConsoleCommand : public Command {
private:
    std::string message; // Сообщение для вывода

public:
    PrintConsoleCommand(const std::string& message);

    void execute() override;
};

#endif
