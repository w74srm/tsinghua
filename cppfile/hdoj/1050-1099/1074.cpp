#include <cstdio>
#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <sstream>
#include <string>
using namespace std;
#define inf 0x3f3f3f3f
struct pp
{
    string name; //课名字
    int cost;    //写完需要的时间
    int dead;    //还有几天交
} ss[20];        //存课的信息
struct ps
{
    int fa, zj, soce, time;
    //fa 父节点 //zj 记录放的那本书 //soce 扣掉的分数  //做完作业所需的时间
} dp[1 << 15];
int main()
{
    ios::sync_with_stdio(false); //去cin同步  听说会减时间
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        memset(dp, 0, sizeof(dp)); //初始化
        for (int i = 0; i < n; i++)
            cin >> ss[i].name >> ss[i].dead >> ss[i].cost;
        int end = 1 << n;
        for (int i = 1; i < end; i++) //枚举任意一种情况  例如 1 1 0  前两门完成  0 0 1 最后一门完成
        {
            dp[i].soce = inf;                //初始化 为了找最小所以Inf
            for (int j = n - 1; j >= 0; j--) //看前一步是写的哪一门课的作业  倒着来的原因：If there are more than one orders, you should output the alphabet smallest one.  要输出字典序最小的
            {
                int temp = 1 << j; // temp 代表课的二进制   例第二门课  temp = 1<<(1)（从 0 开始的，所以是 1）就是 1 0 表示写的第二门课
                if (temp & i)      //看 i 是由那种状态过来的
                {
                    int tem = i - temp;                              //前一种状态
                    int tt = dp[tem].time + ss[j].cost - ss[j].dead; //扣掉的分数  ==写完前一门的时间 + 需要写的时间 - 要交的天数
                    if (tt < 0)                                      //扣掉的分数不可能为负数 归 0
                        tt = 0;
                    if (tt + dp[tem].soce < dp[i].soce) //比较  就是取每一种状态过来的最大值
                    {
                        dp[i].soce = tt + dp[tem].soce;         //记录扣掉的分数
                        dp[i].fa = tem;                         //记录父节点
                        dp[i].zj = j;                           //记录写的哪一门课
                        dp[i].time = dp[tem].time + ss[j].cost; //记录写完所需时间
                    }
                }
            }
        }
        //下面就是输出了  不多说相信大家都能看懂
        cout << dp[end - 1].soce << endl;
        stack<int> q;
        int tt = end - 1;
        ;
        while (dp[tt].time)
        {
            q.push(dp[tt].zj);
            tt = dp[tt].fa;
        }
        while (!q.empty())
        {
            int k = q.top();
            cout << ss[k].name << endl;
            q.pop();
        }
    }

    return 0;
}