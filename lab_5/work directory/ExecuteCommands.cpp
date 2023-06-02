#include "ExecuteCommands.hpp"

#include <iostream>

// Функция executeCommands для последовательного выполнения команд
void executeCommands(const std::vector<Command*>& commands) {
    for (auto command : commands) {
        command->execute(); // Выполнение команды
    }
}

