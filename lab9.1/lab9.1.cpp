//////////////////////////////////////////////////////////////////////////////
// lab9.1.cpp
// Мигович Вячеслав Вадимович, група РІ-11
//                головний файл проекту – функція main
// Лабораторна робота № 9.1. Простори імен. Варіант 18.
// Обчислити і вивести у вигляді таблиці значення функції ln(x),
// заданої рядом Тейлора, на інтервалі від x_p до x_k з кроком dx
// та точністю e:
//   ln x = сума від n = 0 до нескінченності (-1)^n * (x-1)^(n+1) / (n+1),
//   0 < x <= 2.

#include <iostream>
#include <iomanip>
#include <cmath>

#include "sum.h"
#include "var.h"

using namespace std;

using namespace nsSum;
using namespace nsVar;

int main()
{
    cout << "x_p = "; cin >> x_p;
    cout << "x_k = "; cin >> x_k;
    cout << "dx  = "; cin >> dx;
    cout << "e   = "; cin >> e;
    cout << endl;

    if (x_p <= 0 || x_k > 2 || dx <= 0)   // ряд збігається лише при 0 < x <= 2
    {
        cout << "Error: must be 0 < x_p, x_k <= 2, dx > 0" << endl;
        return 1;
    }

    // заголовок і шапка таблиці
    cout << "     ln(x) = sum (-1)^n * (x-1)^(n+1) / (n+1)" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "|" << setw(8) << "x" << " |"
         << setw(12) << "ln(x)" << " |"
         << setw(12) << "S" << " |"
         << setw(8) << "n" << " |" << endl;
    cout << "---------------------------------------------------" << endl;

    x = x_p;
    while (x <= x_k + 1e-9)               // 1e-9 – щоб через похибку double
                                          // не загубити останнє x
    {
        sum();                            // обчислення суми ряду для x

        cout << fixed
             << "|" << setw(8) << setprecision(3) << x << " |"
             << setw(12) << setprecision(6) << log(x) << " |"
             << setw(12) << setprecision(6) << s << " |"
             << setw(8) << n + 1 << " |" << endl;  // доданки з номерами 0..n

        x += dx;
    }
    cout << "---------------------------------------------------" << endl;

    return 0;
}
