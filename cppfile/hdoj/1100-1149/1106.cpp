#include<stdio.h>
#include<string.h>
int main()
{
    char str[1010];
    int a[1010];
    int i,j,k,t,sum;
    while(~scanf("%s",str))
    {
        getchar();
        for(i=0,k=0;i<strlen(str);i++)
        {
            for(j=i,sum=0;i<strlen(str)&&str[j]!='5';i++,j++)//当遇到不是5的 数字，运行循环，并将该数字存到数组a中
            {
                sum*=10;
                sum+=str[j]-'0';
            }
            if(i!=0&&str[i-1]!='5')
            a[k++]=sum;
        }
        //将数字啊的数字进行排序。冒泡排序法。
 
 
        for(i=0;i<k;i++)
        {
            for(j=i+1;j<k;j++)
            if(a[i]>a[j]){t=a[i];a[i]=a[j];a[j]=t;}
        }
        for(i=0;i<k;i++)
        if(i!=k-1)
        printf("%d ",a[i]);
        else
        printf("%d\n",a[i]);
    }
    return 0;
}