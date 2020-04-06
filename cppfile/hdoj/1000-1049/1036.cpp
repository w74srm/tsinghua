#include <iostream>
#include <cmath>
using namespace std;
 
int n;
double d;
int t;
int totalTime;
bool flag;
void input();
void output();
 
int main()
{
	cin >> n >> d;
	while (cin >> t)
	{
		totalTime = 0;
		flag = true;
		input();
		output();
	}
	return 0;
}
 
void input()
{
	for (int i = 0; i < n; i++)
	{
		int temp;
		char c;
		cin >> c;
		if (c == '-')
		{
			flag = false;
			for (int i = 0; i < 6; i++)
				cin.get();
		}
		else
		{
			totalTime += ((int)c - 48) * 60 * 60;
			cin.get();
			cin >> temp;
			totalTime += temp * 60;
			cin.get();
			cin >> temp;
			totalTime += temp;
		}
	}
}
 
void output()
{
	if (t >= 0 && t <= 9)
		cout << "  " << t << ": ";
	else if (t >= 10 && t <= 99)
		cout << " " << t << ": ";
	else
		cout << t << ": ";
 
	if (flag == true)
	{
		double s = totalTime / d;
		int speed = round(s);
		int minute = speed / 60;
		int second = speed - minute * 60;
		if (second>=0 && second<=9)
			cout << minute << ":0" << second << " min/km" << endl;
		else
			cout << minute << ":" << second << " min/km" << endl;
	}
	else
		cout << "-" << endl;
}