#include <iostream>
#include <string>
#include <cmath>
using namespace std;
 
bool flag;
string Klein(int target, string &s);
 
int main()
{
	int target;
	string s;
	while (cin >> target >> s)
	{
		if (target == 0 && s == "END")
			break;
 
		flag = false;
		string K = Klein(target, s);
		if (flag)
			cout << K << endl;
		else
			cout << "no solution" << endl;
	}
	return 0;
}
 
string Klein(int target, string &s)
{
	int v, w, x, y, z;
	int toNum[30]; 
	string temp, max = "AAAAA";
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		toNum[i] = int(s[i] - 64);
	}
	for (int v = 0; v < len; v++)
		for (int w = 0; w < len; w++)
			for (int x = 0; x < len; x++)
				for (int y = 0; y < len; y++)
					for (int z = 0; z < len; z++)
						if (toNum[v] - pow(toNum[w], 2) + pow(toNum[x], 3) - pow(toNum[y], 4) + pow(toNum[z], 5) == target)
						{
							if (v != w && v != x && v != y && v != z && w != x && w != y && w != z && x != y && x != z && y != z)
							{
								temp.push_back(s[v]);
								temp.push_back(s[w]);
								temp.push_back(s[x]);
								temp.push_back(s[y]);
								temp.push_back(s[z]);
							}
							if (temp > max)
							{
								max = temp;
								flag = true;
							}
							temp.clear(); 
						}
	return max;
}