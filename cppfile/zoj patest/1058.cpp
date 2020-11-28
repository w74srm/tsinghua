#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d, e, f, g;
    scanf("%d.%d.%d %d.%d.%d", &a, &b, &c, &d, &e, &f);
    cout << ((f + c) / 29 + (b + e)) / 17 + a + d << "." << ((f + c) / 29 + (b + e)) % 17 << "." << (f + c) % 29;
    return 0;
}