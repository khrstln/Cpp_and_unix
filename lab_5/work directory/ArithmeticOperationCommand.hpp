#ifndef ARITHMETIC_OPERATION_COMMAND_HPP
#define ARITHMETIC_OPERATION_COMMAND_HPP

#include "Command.hpp"

// Класс ArithmeticOperationCommand (команда арифметической операции)
class ArithmeticOperationCommand : public Command {
private:
    char operator_; // Оператор (+, -, *, /)
    float operand1; // Первый операнд
    float operand2; // Второй операнд

public:
    ArithmeticOperationCommand(char op, float operand1, float operand2);

    void execute() override;
};

#endif
