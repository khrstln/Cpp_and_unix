# ЛР #3: [C++ & UNIX]: C++ CLI / FUNCTION / LOOP / RECURSION #

## Цель ##

Познакомить студента с основными алгоритмическими конструкциями, которые будут использоваться для создания CLI программы. 
Далее продемонстрировать эффективность использования механизма рекурсии.
С++ алгоритмы: CLI Калькулятор вещественных чисел +, -, ^, . Реализация с
использованием только функций, условий, циклов, + и -. Вид команд в консоли: calc
plus / minus / power; Ханойская башня, результат корректной последовательности

## Отчет ##

1. [С++ CLI CALC] Создать программу CALC с интерфейсом CLI

Создать программу под названием CALC, которая будет принимать на вход 3
аргумента (2 операнда и 1 оператор). Оператор может быть: +, -, ^. Реализация
операторов только с использованием функций, условий, циклов, +, - и *.

```C++
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
```

2. [C++ RECURSION] Решить задачу ханойской башни с использованием рекурсии.

Описание: Ханойская башня является одной из популярных головоломок XIX века.
Даны три стержня, на один из которых нанизаны восемь колец, причём кольца
отличаются размером и лежат меньшее на большем. Задача состоит в том, чтобы
перенести пирамиду из восьми колец за наименьшее число ходов на другой
стержень. За один раз разрешается переносить только одно кольцо, причём нельзя
класть большее кольцо на меньшее.
Результат обнаруженной последовательности шагов записать в виде двусвязного
списка. В конце программы сделать вывод этого списка на экран. Освободить
память списка перед завершением программы.

```C++
#include <iostream>
#include<string>
#include <list>

using namespace std;

void Tower(int n, char from_rod, char to_rod, char aux_rod, list<string> &steps) {
    if (n == 1) {
        steps.push_back("Move disk 1 from " + string(1, from_rod) + " to " + string(1, to_rod));
        return;
    }

    Tower(n - 1, from_rod, aux_rod, to_rod, steps);
    steps.push_back("Move disk " + to_string(n) + " from " + string(1, from_rod) + " to " + string(1, to_rod));
    Tower(n - 1, aux_rod, to_rod, from_rod, steps);

}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    list<string> steps;
    Tower(n, 'A', 'B', 'C', steps);

    for (string step : steps) {
        cout << step << endl;
    }
    steps.clear();
    return 0;
}
```
