
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
 
const int M = 26 * 26 * 26;	
vector<int> v[M];	
vector<int> node;	
int visited[M] = { 0 };
int w[M] = { 0 };
int n, k;	
int cnt = 0;
int pnum;
int maxtime;
int headtime;
int headId;
 
int toId(string &s);
string toName(int x);
void dfs(int start);
 
int main()
{
	cin >> n >> k;
 
	for (int i = 0; i < n; i++)
	{
		string s1, s2;
		int wgt;
		cin >> s1 >> s2 >> wgt;
 
		int d1 = toId(s1);
		int d2 = toId(s2);
		v[d1].push_back(d2);
		v[d2].push_back(d1);
		w[d1] += wgt;
		w[d2] += wgt;
		node.push_back(d1);
	}
 
	map<string, int> h_map;
	vector<int>::iterator it;
	for (it = node.begin(); it < node.end(); it++)
	{
		pnum = 0;
		maxtime = 0;
		headtime = 0;
		if (visited[*it] == 0)
			dfs(*it);
 
		if (pnum > 2 && maxtime > 2 * k)
		{
			cnt++;
			string name = toName(headId);
			h_map[name] = pnum;
		}
	}
 
	cout << cnt << endl;
	if (cnt != 0)
	{
		map<string, int>::iterator it;
		for (it = h_map.begin(); it != h_map.end(); it++)
			cout << it->first << ' ' << it->second << endl;
	}
 
	return 0;
}
 
int toId(string &s)
{
	return ((s[0] - 'A') * 26 * 26 + (s[1] - 'A') * 26 + (s[2] - 'A'));
}
 
string toName(int x)
{
	string s(3, 0);
	s[2] = x % 26 + 'A';
	s[1] = x / 26 % 26 + 'A';
	s[0] = x / 26 / 26 + 'A';
 
	return s;
}
 
void dfs(int start)
{
	visited[start] = 1;
	pnum++;
	maxtime += w[start];
	if (w[start] > headtime)
	{
		headtime = w[start];
		headId = start;
	}
 
	for (unsigned i = 0; i < v[start].size(); i++)
	{
		if (visited[v[start][i]] == 0)
			dfs(v[start][i]);
	}
 
	return;
}