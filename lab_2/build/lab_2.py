import numpy as np
import timeit

input_n = input("Введите число итераций: ")

x = np.random.random()
print(x)

def f(x):
    return x**2 - x**2 + x*4 - x*5 + x + x

def time_measuring(function):
    try:
        n = int(input_n)
        print("Это целое число")
        print()
    except ValueError:
        print("Это не целое число!")
        return None
    time = timeit.timeit(stmt = "f(x)", globals = globals(), number = n)    
    return (n, time)

while True:
    n, time_res = time_measuring(f)
    if time_res == None:
        break
    else:
        print("Время выполнения", n, "итераций равно", time_res)
        print()
        answer = input("Хотите заново выполнить вычисления? (да/нет): ")
        if answer == "нет":
            break