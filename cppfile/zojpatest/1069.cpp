#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
 
bool compare(int a, int b)
{
    return a > b;
}
int* kaprekar(int *a)
{
 
    int b[4];
    for (int i = 0; i < 4; i++)
    {
        b[i] = a[i];
    }
    sort(a, a + 4);
    sort(b, b + 4, compare);
    int sum1 = 0, sum2 = 0;
    for (int i = 3; i >=0; i--)
    {
        sum1 += a[i] * pow(10, 3 - i);
        sum2 += b[i] * pow(10, 3 - i);
    }
    cout << b[0] << b[1] << b[2] << b[3];
    cout << " " << "-" << " ";
    cout << a[0] << a[1] << a[2] << a[3];
    int temp = sum2 - sum1;
    for (int i = 3; i >= 0; i--)
    {
        a[i] = temp % 10;
        temp = temp / 10;
    }
    cout << " " << "=" << " ";
    cout << a[0] << a[1] << a[2] << a[3]<<endl;
 
    return a;
}
int main()
{
    int a1;
    cin >> a1;
    int *a = new int[4];
    for (int i = 3; i >= 0; i--)
    {
        a[i] = a1 % 10;
        a1 = a1 / 10;
    }
    int temp = 0;
    while (true)
    {
        if (temp != 6174)
        {
            a = kaprekar(a);
            temp = 0;
            for (int i = 3; i >= 0; i--)
            {
                temp += a[i] * pow(10, 3 - i);
            }
            if (temp == 0 || temp == 6174)
                break;
        }
 
    }
    return 0;
}