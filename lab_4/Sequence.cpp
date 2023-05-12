#include <iostream>
#include <cmath>
#include <time.h>


double func1(const double &x) {
    double res;
    res = pow(x, 2) - pow(x, 2) + 4*x - 5*x + x + x;
    // std::cout << res << "\n";
    return res; 
}

double func2 (const double &x) {
    double res;
    res = x + x;
    // std::cout << res << "\n";
    return res;
}

double func3(const double &f1, const double &f2) {
    double res;
    res = f1 + f2 - f1;
    return res;
}



double time_seq (const double &x, const int &n) {
    clock_t start = clock();
    for (int i = 0; i < n; i++) {
        double f1 = func1(x);
        double f2 = func2(x);
        double f3 = func3(f1, f2);
    }
    clock_t end = clock();
    double seconds = (double)(end - start)/CLOCKS_PER_SEC;
    return seconds;
}

int main() {
    double x = 0.1415;
    int n = 100000;
    double time_1 = time_seq(x, n);

    std::cout << "Time of " << n << " loops: " << time_1 << " seconds" << "\n";

    return 0;
}