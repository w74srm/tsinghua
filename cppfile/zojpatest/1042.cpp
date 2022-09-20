#include <iostream>
using namespace std;

int cards[54];
char kinds[5] = {'S', 'H', 'C', 'D', 'J'};

void initcards()
{
    for (int i = 1; i <= 54; i++)
    {
        cards[i - 1] = i;
    }
}

void shuffle(int order[54])
{
    int temp[54];
    for (int i = 0; i < 54; i++)
    {
        temp[order[i] - 1] = cards[i];
    }
    for (int i = 0; i < 54; i++)
    {
        cards[i] = temp[i];
    }
}

int main()
{
    initcards();
    int k;
    cin >> k;
    int order[54];
    for (int i = 0; i < 54; i++)
    {
        cin >> order[i];
    }
    for (int i = 0; i < k; i++)
    {
        shuffle(order);
    }
    for (int i = 0; i < 54; i++)
    {
        int flag = (cards[i] - 1) / 13;
        int num = cards[i] % 13;
        if (num == 0)
            num = 13;
        cout << kinds[flag] << num;
        if (i != 53)
            cout << ' ';
    }
    return 0;
}