#include <iostream> 
#include <cmath> 
#include <time.h> 
#include <stdlib.h>

using namespace std;

double func(const int &x, const int &n) {
    clock_t start = clock();
    for(int i = 0; i < n; ++i)
    {
        float res = pow(x, 2) - pow(x, 2) + x * 4 - x * 5 + x + x;
    }; 
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << seconds << endl;
    printf("Time is %.5e seconds\n", seconds);
    return seconds;
}

int main()
{
    string answer = "y";
    while (answer == "y")
    {
        float x = rand() % 2+100;

        int n; 
        std::cout << "Enter the number of iterations:" << endl;
        std::cin >> n;

        if(!std::cin.good())
        {
            std::cout << "That's not integer!!!" << endl;
            return 0;
        }
        std::cout << "That's integer" << endl;
        double res =  func(x, n);
        std::cout << "Do you want to repeat?: (y/n)" << endl;
        std::cin >> answer;
    }
}