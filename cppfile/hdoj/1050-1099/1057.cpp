#include<cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define max 20

char crt[4] = {'.','!','X','#'};
int cb[max][max];
int ca[max][max];
int d[max];

using namespace std;

int output(int cur[][max]);
int simulation(int before[][max],int after[][max]);

int main()
{
    int n,m;
    cin >> n;
    while(n--)
    {
        memset(cb,0,sizeof(cb));
        memset(ca,0,sizeof(ca));
        cin >> m;
        for(int i = 0;i < 16;i++)
            cin >> d[i];
        for(int i = 0;i < max;i++)
            for(int j = 0;j < max;j++)
                cin >> cb[i][j];
        for(int i = 0;i < m;i++)
        {
            if(i % 2 == 0)
                simulation(cb,ca);
            else
                simulation(ca,cb);
        }
        if(m % 2 == 0)
            output(cb);
        else
            output(ca);
        if(n > 0)
            cout << endl;
    }
    return 0;
}

int output(int cur[][max])
{
    for(int i = 0;i < max;i++)
    {
        for(int j = 0;j < max;j++)
        {
            switch(cur[i][j])
            {
                case 0 : cout << crt[0]; break;
                case 1 : cout << crt[1]; break;
                case 2 : cout << crt[2]; break;
                case 3 : cout << crt[3]; break;
            }
        }
        cout << endl;
    }
    return 0;
}

int simulation(int before[][max],int after[][max])
{
    int sum,rs;
    for(int i = 0;i < max;i++)
        for(int j = 0;j < max;j++)
        {
            sum = 0;
            sum += (i > 0 ? before[i-1][j] : 0);
            sum += (j > 0 ? before[i][j-1] : 0);
            sum += (i < (max-1) ? before[i+1][j] : 0);
            sum += (j < (max-1) ? before[i][j+1] : 0);
            sum += before[i][j];
            rs = before[i][j] + d[sum];
            if(rs > 3)
                rs = 3;
            if(rs < 0)
                rs = 0;
            after[i][j] = rs;
        } 
    return 0;
}