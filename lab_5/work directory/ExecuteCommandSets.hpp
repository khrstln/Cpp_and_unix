#ifndef EXECUTE_COMMAND_SETS_HPP
#define EXECUTE_COMMAND_SETS_HPP

#include <vector>
#include <thread>
#include <chrono>
#include "Command.hpp"

// Функция executeCommandSets для параллельного исполнения наборов команд
void executeCommandSets(const std::vector<std::vector<Command*>>& commandSets);

#endif

