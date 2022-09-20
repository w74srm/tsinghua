#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct fraction
{
    long long a, b;
    long long k;
    fraction() : k(0) {}
};

int gcd(long long a, long long b)
{
    return !b ? a : gcd(b, a % b);
}

fraction reduction(fraction f)
{
    fraction ft;
    if (f.b < 0)
    {
        ft.a = -f.a;
        ft.b = -f.b;
        f.a = -f.a;
        f.b = -f.b;
    }
    if (f.a == 0)
    {
        ft.a = 0;
        ft.b = 1;
        f.a = 0;
        f.b = 1;
    }

    ft.a = f.a / gcd(abs(f.a), f.b);
    ft.b = f.b / gcd(abs(f.a), f.b);
    if (abs(ft.a) >= ft.b)
    {
        if (f.a < 0)
        {
            ft.k = -abs(ft.a) / ft.b;
            ft.a = abs(ft.a) % ft.b;
        }
        else
        {
            ft.k = abs(ft.a) / ft.b;
            ft.a = abs(ft.a) % ft.b;
        }
    }
    return ft;
}

fraction add(fraction f1, fraction f2)
{
    fraction f;
    f.a = f1.a * f2.b + f2.a * f1.b;
    f.b = f1.b * f2.b;
    return reduction(f);
}

fraction substract(fraction f1, fraction f2)
{
    fraction f;
    f.a = f1.a * f2.b - f2.a * f1.b;
    f.b = f1.b * f2.b;
    return reduction(f);
}

fraction multiply(fraction f1, fraction f2)
{
    fraction f;
    f.a = f1.a * f2.a;
    f.b = f1.b * f2.b;
    return reduction(f);
}

fraction divide(fraction f1, fraction f2)
{
    fraction f;
    f.a = f1.a * f2.b;
    f.b = f1.b * f2.a;
    return reduction(f);
}

void printFraction(fraction f)
{
    if (f.k > 0)
    {
        if (f.a != 0)
        {
            cout << f.k << " " << f.a << "/" << f.b;
        }
        else
            cout << f.k;
    }
    else if (f.k == 0)
    {
        if (f.a > 0)
        {
            cout << f.a << "/" << f.b;
        }
        else if (f.a == 0)
            cout << 0;
        else
            cout << "(" << f.a << "/" << f.b << ")";
    }
    else
    {
        if (f.a != 0)
            cout << "(" << f.k << " " << f.a << "/" << f.b << ")";
        else
            cout << "(" << f.k << ")";
    }
}

int main()
{
    fraction f1, f2;
    scanf("%lld/%lld %lld/%lld", &f1.a, &f1.b, &f2.a, &f2.b);
    printFraction(reduction(f1));
    cout << " + ";
    printFraction(reduction(f2));
    cout << " = ";
    printFraction(add(f1, f2));
    cout << endl;
    printFraction(reduction(f1));
    cout << " - ";
    printFraction(reduction(f2));
    cout << " = ";
    printFraction(substract(f1, f2));
    cout << endl;
    printFraction(reduction(f1));
    cout << " * ";
    printFraction(reduction(f2));
    cout << " = ";
    printFraction(multiply(f1, f2));
    cout << endl;
    printFraction(reduction(f1));
    cout << " / ";
    printFraction(reduction(f2));
    cout << " = ";
    if (f2.a != 0)
        printFraction(divide(f1, f2));
    else
        cout << "Inf";
    cout << endl;
    return 0;
}