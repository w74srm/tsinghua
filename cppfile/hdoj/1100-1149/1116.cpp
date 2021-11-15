#include<cstdio>
#include<cstring>
int f[110],in[33],out[33],book[33];
int getf(int x)
{
    if(x==f[x])
        return x;
    return f[x]=getf(f[x]);
}
void init()
{
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(book,0,sizeof(book));
    for(int i=0; i<30; i++)
        f[i]=i;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    int as=t;
    while(t--)
    {
        init();
        char str[1100];
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%s",str);
            int l=strlen(str);
            int t1=getf(str[0]-'a');
            int t2=getf(str[l-1]-'a');
            if(t1!=t2)   //并查集
                f[t2]=t1;
            in[str[0]-'a']++;//入度+1
            out[str[l-1]-'a']++;  //出度+1
            book[str[0]-'a']=book[str[l-1]-'a']=1;  //这个字母出现过
        }
        int a=0,b=0,ans=0,flag=1,mark=1;
        for(int i=0; i<26; i++)
        {
            if(book[i])  //出现过的字母
            {
                if(f[i]==i)//找到祖先
                    ans++;
                if(in[i]!=out[i])//入度和出度不等
                {
                    if(in[i]-out[i]==1)  //入度和出度之差为1
                        a++;
                    else if(out[i]-in[i]==1) //出度和入度之差为1
                        b++;
                    else             //不满足条件
                        mark=0;
                }
                if(ans>1||!mark)
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag&&mark)
        {
            if((!a&&!b)||(a==1&&b==1))
                printf("Ordering is possible.\n");
            else
                printf("The door cannot be opened.\n");
        }
        else
            printf("The door cannot be opened.\n");
    }
}