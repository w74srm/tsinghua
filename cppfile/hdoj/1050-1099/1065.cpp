#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.1415926;
 
int main()
{
	int n;
	cin >> n;
	double x, y, r;
	int year;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y;
		r = sqrt(x*x + y*y);
		year = ceil(PI*r*r / 100); //向上取整
 
		cout << "Property " << i << ": This property will begin eroding in year " << year << "." << endl;
	}
	cout << "END OF OUTPUT." << endl;
	return 0;
}