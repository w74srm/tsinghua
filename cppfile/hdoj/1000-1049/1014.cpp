#include <iostream>
#include<cstring>
#include<cstdlib>
#include<stdio.h>
using namespace std;
int main()
{
    int step,mode;
    while(cin>>step>>mode){
        int i,j,flag;
        for(i=0;i<mode;i++)
        {
            char num[100001]={'0'};
            int seed;
            seed=(i+step%mode)%mode;
            num[seed]='1';
            for(j=1;j<mode;j++)
                {
                    flag=0;
                    seed=(seed+step%mode)%mode;
                    if(num[seed]=='1')
                    {
                        flag=1;
                        break;
                    }
                    else num[seed]='1';
                }
                if(!flag)
                    break;
        }
        printf("%10d%10d    ",step,mode);
        if(!flag)
            printf("%-s\n","Good Choice");
            else printf("%-s\n","Bad Choice");
            printf("\n");
    }
    return 0;
}