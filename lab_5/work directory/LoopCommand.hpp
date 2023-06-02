#ifndef LOOP_COMMAND_HPP
#define LOOP_COMMAND_HPP

#include <vector>
#include "Command.hpp"

// Класс LoopCommand (команда цикла)
class LoopCommand : public Command {
private:
    int count; // Количество итераций цикла
    std::vector<Command*> commands; // Вложенные команды цикла

public:
    LoopCommand(int count, const std::vector<Command*>& commands);

    void execute() override;
};

#endif
