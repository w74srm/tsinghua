#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 510;
const int INF = 1000000000;
struct station
{
	double price, dis;
}st[maxn];
bool cmp(station a, station b)
{
	return a.dis < b.dis;
}
int main()
{
	int n;
	double Cmax, D, Davg;
	scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf%lf", &st[i].price, &st[i].dis);
	}
	st[n].price = 0;
	st[n].dis = D;
	sort(st, st + n, cmp);
	if (st[0].dis != 0)
	{
		printf("The maximum travel distance = 0.00\n");
	}
	else
	{
		int now = 0;
		double ans = 0, nowTank = 0, MAX = Cmax*Davg;
		while (now < n)
		{
			int k = -1;
			double priceMin = INF;
			for (int i = now + 1; i <= n&&st[i].dis - st[now].dis <= MAX; i++)
			{
				if (st[i].price < priceMin)
				{
					priceMin = st[i].price;
					k = i;
					if (priceMin < st[now].price)
					{
						break;
					}
				}
			}
			if (k == -1)break;
			double need = (st[k].dis - st[now].dis) / Davg;
			if (priceMin < st[now].price)
			{
				if (nowTank < need) {
					ans += (need - nowTank)*st[now].price;//补足need
					nowTank = 0;//到达加油站k后油箱内油量为0
 
				}
				else//如果当前油量超过need
				{
					nowTank -= need;//直接到达加油站k	
				}
			}
			else//如果加油站k的油价高于当前油价
			{
				ans += (Cmax - nowTank)*st[now].price;//将油箱加满
				//到达加油站k后油箱内油量为Cmax-need
				nowTank = Cmax - need;
			}
			now = k;//到达加油站k，进入下一层循环
		}
		if (now == n)//能到达终点
		{
			printf("%.2f\n", ans);
		}
		else//不能到达终点
		{
			printf("The maximum travel distance = %.2f\n", st[now].dis + MAX);
		}
	}
	return 0;
}