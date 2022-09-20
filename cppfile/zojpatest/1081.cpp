#include <cstdio>
#include <algorithm>

typedef long long LL;
struct fraction
{
    LL numerator, denumerator;
    LL Integer;
    fraction() : Integer(0), numerator(0), denumerator(1) {}
};

LL gcd(LL a, LL b)
{
    return !b ? a : gcd(b, a % b);
}

fraction reduce(fraction f)
{
    if (f.denumerator < 0)
    {
        f.numerator = -f.numerator;
        f.denumerator = -f.denumerator;
    }
    if (f.numerator == 0)
    {
        f.denumerator = 1;
    }
    LL d = gcd(abs(f.numerator), f.denumerator);
    f.denumerator /= d;
    f.numerator /= d;
    bool flag = false;
    if (f.numerator < 0)
        flag = true;
    if (abs(f.numerator) >= f.denumerator)
    {
        f.Integer = abs(f.numerator) / f.denumerator;
        f.numerator = abs(f.numerator) % f.denumerator;
        if (flag)
        {
            f.Integer = -f.Integer;
            f.numerator = -f.numerator;
        }
    }

    return f;
}

fraction add(fraction f1, fraction f2)
{
    fraction f;
    f.denumerator = f1.denumerator * f2.denumerator;
    f.numerator = f1.numerator * f2.denumerator + f1.denumerator * f2.numerator;
    f = reduce(f);
    f.Integer = f.Integer + f1.Integer + f2.Integer;
    return f;
}

void print(fraction f)
{
    if (!f.Integer)
    {
        if (!f.numerator)
            printf("0");
        else
            printf("%lld/%lld", f.numerator, f.denumerator);
    }
    else
    {
        if (!f.numerator)
            printf("%lld", f.Integer);
        else
            printf("%lld %lld/%lld", f.Integer, f.numerator, f.denumerator);
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    fraction f;
    fraction sum;
    for (int i = 0; i < N; i++)
    {
        scanf("%lld/%lld", &f.numerator, &f.denumerator);
        sum = add(sum, f);
    }
    print(sum);
    return 0;
}