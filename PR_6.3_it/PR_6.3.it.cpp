// PR_6.3.it.cpp
// Варіант 8 (ітераційний спосіб)
// Завдання: обчислення суми додатних елементів одновимірного масиву
// Реалізація за допомогою звичайних функцій та шаблонів функцій (сумарно 6 функцій)
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. Звичайна функція формування масиву
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// 2. Шаблонна функція формування масиву
template <typename T>
void Create(T* a, const int size, const T Low, const T High)
{
    for (int i = 0; i < size; i++)
        a[i] = static_cast<T>(Low + static_cast<double>(rand()) / RAND_MAX * (High - Low));
}

// 3. Звичайна функція виведення масиву
void Print(const int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(6) << a[i];
    cout << endl;
}

// 4. Шаблонна функція виведення масиву
template <typename T>
void Print(const T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(8) << fixed << setprecision(2) << a[i];
    cout << endl;
}

// 5. Звичайна функція обчислення суми додатних елементів
int SumPositive(const int* a, const int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] > 0)
            s += a[i];
    }
    return s;
}

// 6. Шаблонна функція обчислення суми додатних елементів
template <typename T>
T SumPositive(const T* a, const int size)
{
    T s = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] > 0)
            s += a[i];
    }
    return s;
}

template <typename T>
T SumPositiveTemplate(const T* a, const int size)
{
    return SumPositive<T>(a, size);
}

#if !defined(_WINDLL)
int main()
{
    srand((unsigned)time(NULL));

    const int n = 10;
    int a[n];
    const int Low = -10;
    const int High = 10;

    // 1) Опрацювання за допомогою звичайних функцій
    Create(a, n, Low, High);
    cout << "1. Regular functions (int array a):" << endl;
    Print(a, n);
    int s1 = SumPositive(a, n);
    cout << "Sum of positive elements (regular SumPositive) = " << s1 << endl << endl;

    // 2) Опрацювання за допомогою шаблонів функцій для int
    Create<int>(a, n, Low, High);
    cout << "2. Template functions for int (array a):" << endl;
    Print<int>(a, n);
    int s2 = SumPositive<int>(a, n);
    cout << "Sum of positive elements (template SumPositive<int>) = " << s2 << endl << endl;

    // 3) Опрацювання за допомогою шаблонів функцій для double
    double b[n];
    const double LowD = -10.0;
    const double HighD = 10.0;
    Create(b, n, LowD, HighD);
    cout << "3. Template functions for double (array b):" << endl;
    Print(b, n);
    double s3 = SumPositive(b, n);
    cout << "Sum of positive elements (template SumPositive<double>) = " << s3 << endl;

    return 0;
}
#endif
