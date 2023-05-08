#include <iostream>
#include <cmath>
#include <string>

int main() {
    std::cout << "Enter an expression: " << "\n";
    std::string expr;
    std::cin >> expr;

    if (expr.find("plus") != expr.npos) {
        size_t pos = expr.find("plus");
        double x = std::stod(expr.substr(0, pos));
        double y = std::stod(expr.substr(pos + 4));
        std::cout  << expr.substr(0, pos) << " + " << expr.substr(pos + 4) << " = " << x + y;
        return 0;
    }

    if (expr.find("minus") != expr.npos) {
        size_t pos = expr.find("minus");
        double x = std::stod(expr.substr(0, pos));
        double y = std::stod(expr.substr(pos + 5));
        std::cout  << expr.substr(0, pos) << " - " << expr.substr(pos + 5) << " = " << x - y;
        return 0;
    }

    if (expr.find("power") != expr.npos) {
        size_t pos = expr.find("power");
        double x = std::stod(expr.substr(0, pos));
        double y = std::stod(expr.substr(pos + 5));
        std::cout  << expr.substr(0, pos) << "^" << expr.substr(pos + 5) << " = " << pow(x, y);
        return 0;
    }
}