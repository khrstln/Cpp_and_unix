#include <iostream>
#include <cmath>
#include <time.h>
#include <thread>

void func1(const double &x, const int &n) {
    double res;
    for (int i = 0; i < n; i++) {
        res = pow(x, 2) - pow(x, 2) + 4*x - 5*x + x + x;
    }
}

void func2 (const double &x, const int &n) {
    double res;
    for (int i = 0; i < n; i++) {
        res = x + x;
    }
}

double f1(const double &x) {
    return pow(x, 2) - pow(x, 2) + 4*x - 5*x + x + x;
}

double f2(const double &x) {
    return x + x;
}

void func3(const double &f1, const double &f2, const int &n) {
    double res;
    for (int i = 0; i < n; i++) {
        res = f1 + f2 - f1;
    }
}


int main() {
    double x = rand()*0.1415;
    std::cout << "x = " << x << "\n";
    int n;
    std::cout << "Enter the number of loops: ";
    std::cin >> n;

    double F1 = f1(x);
    double F2 = f2(x);
    clock_t start1 = clock();
    
    std::thread t1(func1, x, n);
    t1.join();
    clock_t end1 = clock();
    double seconds1 = (double)(end1 - start1)/CLOCKS_PER_SEC;
    std::cout << "Time_1 of " << n << " loops: " << seconds1 << " seconds" << "\n";

    clock_t start2 = clock();
    std::thread t2(func2, x, n);
    t2.join();
    clock_t end2 = clock();
    double seconds2 = (double)(end2 - start2)/CLOCKS_PER_SEC;
    std::cout << "Time_2 of " << n << " loops: " << seconds2 << " seconds" << "\n";

    clock_t start3 = clock();
    func3(F1, F2, n);
    clock_t end3 = clock();
    double seconds3 = (double)(end3 - start3)/CLOCKS_PER_SEC;
    std::cout << "Time_3 of " << n << " loops: " << seconds3 << " seconds" << "\n";

    // std::cout << "Full time of " << n << " loops: " << SECONDS << " seconds" << "\n";

    return 0;
}