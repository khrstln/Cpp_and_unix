#include "ArithmeticOperationCommand.hpp"
#include <iostream>

// Класс ArithmeticOperationCommand (команда арифметической операции)
ArithmeticOperationCommand::ArithmeticOperationCommand(char op, float operand1, float operand2)
    : operator_(op), operand1(operand1), operand2(operand2) {}

void ArithmeticOperationCommand::execute() {
    float result;
    switch (operator_) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            result = operand1 / operand2;
            break;
        default:
            result = 0.0f;
            break;
    }

    std::cout << "Result: " << result << std::endl; // Вывод результата арифметической операции
}

