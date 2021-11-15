#include <iostream>
using namespace std;
int num[1005];
int n, m;
bool isMax()
{
    for (int i = 0; 2 * i + 1 < n; i++)
    {
        if (2 * i + 2 >= n)
            if (num[i] < num[2 * i + 1])
                return false;
        if (2 * i + 2 < n)
            if (num[i] >= num[2 * i + 1] && num[i] >= num[2 * i + 2])
                ;
            else
                return false;
    }
    return true;
}
bool isMin()
{
    for (int i = 0; 2 * i + 1 < n; i++)
    {
        if (2 * i + 2 >= n)
            if (num[i] > num[2 * i + 1])
                return false;
        if (2 * i + 2 < n)
            if (num[i] <= num[2 * i + 1] && num[i] <= num[2 * i + 2])
                ;
            else
                return false;
    }
    return true;
}
void Print(int k)
{
    if (k >= n)
        return;
    Print(2 * k + 1);
    Print(2 * k + 2);
    if (k == 0)
        cout << num[k] << endl;
    else
        cout << num[k] << " ";
}
int main()
{
    cin >> m >> n;
    while (m--)
    {
        for (int i = 0; i < n; i++)
            cin >> num[i];
        int flag = 0;
        if (isMax())
            flag = 1;
        if (isMin())
            flag = 2;
        if (flag == 1)
            cout << "Max Heap" << endl;
        else if (flag == 2)
            cout << "Min Heap" << endl;
        else
            cout << "Not Heap" << endl;
        Print(0);
    }
    return 0;
}