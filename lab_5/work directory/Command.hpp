#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include <sstream>

#ifndef COMMAND_HPP
#define COMMAND_HPP

// Базовый класс Command (команда)
class Command {
public:
    virtual void execute() = 0; // Виртуальная функция для выполнения команды
};

#endif
