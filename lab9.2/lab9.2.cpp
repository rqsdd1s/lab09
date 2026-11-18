//////////////////////////////////////////////////////////////////////////////
// lab9.2.cpp
// Мигович Вячеслав Вадимович, група РІ-11
// Лабораторна робота № 9.2. Директиви препроцесора. Частина 1. Варіант 18.
// Обчислити
//        | max(x^3, (x+y)^2),     z > 10
//    w = |
//        | min(|x-z|, |x+z|),     z <= 10
// Препроцесор на основі значення z визначає, яка гілка компілюється.

#include <iostream>

#include "macros.h"                       // власний файл з макросами

#ifndef Z                                 // якщо в macros.h немає Z –
#error "Z is not defined"                 // зупинити компіляцію з помилкою
#endif

using namespace std;

// Обчислює значення w для заданих x та y (z задано макросом Z).
double Calc(double x, double y)
{
#if FIRST_BRANCH                          // z > 10 – компілюється перша гілка
    return MAX(CUBE(x), SQR(x + y));
#else                                     // z <= 10 – компілюється друга гілка
    return MIN(ABS(x - Z), ABS(x + Z));
#endif
}

int main()
{
    double x, y;

    cout << "z = " << Z << endl;
#if FIRST_BRANCH
    cout << "z > 10: w = max(x^3, (x+y)^2)" << endl;
#else
    cout << "z <= 10: w = min(|x-z|, |x+z|)" << endl;
#endif

    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;

    double w = Calc(x, y);
    PRINT(w);                             // макрос виведення результату

    return 0;
}
