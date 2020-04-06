#include <iostream>
#include <cstring>
using namespace std;
 
int main()
{
	char arr[210];
	while (cin >> arr)
	{
		int x = 300, y = 420;
		char direction = 'e';
		cout << x << " " << y << " " << "moveto" << endl;
		x += 10;
		cout << x << " " << y << " " << "lineto" << endl;
		int len = strlen(arr);
		for (int i = 0; i < len; i++)
		{
			switch (direction)
			{
			case 'e':
				if (arr[i] == 'A')
				{
					direction = 's';
					y -= 10;
				}
				else
				{
					direction = 'n';
					y += 10;
				}
				break;
			case 'n': 
				if (arr[i] == 'A')
				{
					direction = 'e';
					x += 10;
				}
				else
				{
					direction = 'w';
					x -= 10;
				}
				break;
			case 'w': 
				if (arr[i] == 'A')
				{
					direction = 'n';
					y += 10;
				}
				else
				{
					direction = 's';
					y -= 10;
				}
				break;
			case 's': 
				if (arr[i] == 'A')
				{
					direction = 'w';
					x -= 10;
				}
				else
				{
					direction = 'e';
					x += 10;
				}
				break;
			}
			cout << x << " " << y << " " << "lineto" << endl;
		}
		cout << "stroke" << endl << "showpage" << endl;
	}
	return 0;
}