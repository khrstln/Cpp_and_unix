#include "LoopCommand.hpp"
#include "ExecuteCommands.hpp"
#include "ExecuteCommandSets.hpp"

// Класс LoopCommand (команда цикла)
LoopCommand::LoopCommand(int count, const std::vector<Command*>& commands)
    : count(count), commands(commands) {}

void LoopCommand::execute() {
    std::vector<std::vector<Command*>> commandSets(count, commands);
    executeCommandSets(commandSets);
}

