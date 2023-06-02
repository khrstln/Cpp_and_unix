#ifndef PRINT_FILE_COMMAND_HPP
#define PRINT_FILE_COMMAND_HPP

#include <string>
#include "Command.hpp"

// Класс PrintFileCommand (команда вывода в файл)
class PrintFileCommand : public Command {
private:
    std::string filename; // Имя файла
    std::string message; // Сообщение для вывода

public:
    PrintFileCommand(const std::string& filename, const std::string& message);

    void execute() override;
};

#endif
