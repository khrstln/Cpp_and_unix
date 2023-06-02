#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <sstream>
#include <vector>
#include "ArithmeticOperationCommand.hpp"
#include "PrintConsoleCommand.hpp"
#include "PrintFileCommand.hpp"
#include "LoopCommand.hpp"

// Функция parseArithmeticOperation для разбора строки арифметической операции
ArithmeticOperationCommand* parseArithmeticOperation(const std::string& line);

// Функция processCommandString для обработки строки команд
std::vector<Command*> processCommandString(const std::string& commandString);

#endif
