#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	vector<int> v;
	cin >> N;
	int d = 0;
	int sum = 0;
	v.push_back(d);
	int i = 0;
	while (N--)
	{
		cin >> d;
		sum += d;
		v.push_back(d + v[i++]);
	}
	int M;
	cin >> M;
	int f, l;
	while (M--)
	{
		cin >> f >> l;
		cout << min(abs(v[f - 1] - v[l - 1]), sum - abs(v[f - 1] - v[l - 1])) << endl;
	}
}