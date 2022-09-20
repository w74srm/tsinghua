#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(int a)
{
    if (a < 2)
        return false;
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

int smallestPrimeSize(int a)
{
    while (!isPrime(a))
    {
        a++;
    }
    return a;
}

int main()
{
    int MSize, N;
    scanf("%d %d", &MSize, &N);
    int size = smallestPrimeSize(MSize);
    vector<bool> hashtable;
    for (int i = 0; i < size; i++)
    {
        hashtable.push_back(true);
    }
    int t;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &t);
        int temp = t % size;
        if (hashtable[temp])
        {
            hashtable[temp] = false;
            printf("%d", temp);
            if (i != N - 1)
                printf(" ");
        }
        else
        {
            int j = (temp + 1) % size, k = 1;
            bool flag = false;
            while (j < size)
            {

                if (hashtable[j])
                {
                    hashtable[j] = false;
                    printf("%d", j);
                    if (i != N - 1)
                        printf(" ");
                    break;
                }
                else
                {
                    k++;
                    if (k == size)
                    {
                        flag = true;
                        break;
                    }
                }
                j = (temp + k * k) % size;
            }
            if (flag)
            {
                printf("-");
                if (i != N - 1)
                    printf(" ");
            }
        }
    }
    return 0;
}