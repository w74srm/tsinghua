#include <iostream>
#include <set>
using namespace std;
int book[50001]; //大数组一定要开全局
struct node
{
    int num, cnt;
    friend bool operator<(const node &a, const node &b)
    {
        if (a.cnt != b.cnt)
            return a.cnt > b.cnt;
        else
            return a.num < b.num;
    }
};
int main()
{
    int n, k, num;
    cin >> n >> k;
    set<node> s; //set集合也是一个有序的集合，根据重载的<进行排序
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        if (i != 0)
        {                       //第一次不进行推荐，因为第一次用户刚进入，无法推荐，只能从第二个开始推荐
            printf("%d:", num); //从第二个开始打印
            int cnt = 0;
            for (auto it = s.begin(); cnt < k && it != s.end(); it++)
            { //打印系统统计之前的数据
                printf(" %d", (*it).num);
                cnt++;
            }
            printf("\n");
        }
        auto j = s.find(node{num, book[num]}); //查看当前这个值是否存在于数组中，不存在直接插入该条数据，负责只要更新此数据
        if (j != s.end())
            s.erase(j);
        book[num]++;
        s.insert(node{num, book[num]}); //插入数据的时候，set自动帮我们在排序
    }
    system("pause");
    return 0;
}