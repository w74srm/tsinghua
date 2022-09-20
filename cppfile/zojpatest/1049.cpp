#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int nums;
	scanf("%d", &nums);

	int res = 0,temp,index = 1,low = 0;
	while (nums)
	{
		temp = nums % 10;
		nums /= 10;
		if (temp == 0) res += nums * index;
		else if (temp == 1) res += nums*index + low + 1;
		else res += (nums + 1) * index;
		low += temp * index;
		index *= 10;
	}


	printf("%d\n", res);
    return 0;
}
