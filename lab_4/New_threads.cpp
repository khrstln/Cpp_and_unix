#include <iostream>
#include <cmath>
#include <time.h>
#include <thread>
#include <mutex>


using namespace std;

float f1(const float &x) {
    return pow(x, 2) - pow(x, 2) + 4*x - 5*x + x + x;
}

float f2(const float &x) {
    return x + x;
}

int main() {
    float x = 0.1415;
    int n = 100000;
    float res_1[n];
    float res_2[n];
    float res_3;
    std::mutex m;
    clock_t start = clock();
    
    std::thread th1([&res_1, &x, &n, &m]()
    {   
        for (int i = 0; i<n; i++){
            m.lock();
            res_1[i] = f1(x);
            m.unlock();
        }
    });
    

    std::thread th2([&res_2, &x, &n, &m]()
    {   
        for (int i = 0; i<n; i++){
            m.lock();
            res_2[i] = f2(x);
            m.unlock();
        }
    });

    for (int i = 0; i < n; i++){
        res_3 = res_1[i] + res_2[i] - res_1[i];
    }
    th1.join();
    th2.join();
    clock_t end = clock();
    double seconds = (double)(end - start)/CLOCKS_PER_SEC;
    std::cout << "Time of " << n << " loops: " << seconds << " seconds" << "\n";
    return 0;
}