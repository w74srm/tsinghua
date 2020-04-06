
#include <algorithm>  
#include <iostream>  
using namespace std;
 
int main()
{
	double s_m = 10 / 59.0, m_h = 120 / 11.0, h_s = 120 / 719.0,
		tsm = 3600. / 59., tmh = 43200. / 11., ths = 43200. / 719.;
	double result = 0, d, f1, f2, f3, e1, e2, e3, op, ed;//d是度数  
	while (cin>>d && d != -1)
	{
		if (d == 0)
			printf("100.000\n");
		else
		{
			result = 0;
			for (f1 = s_m*d, e1 = tsm - s_m*d; e1 <= 43200; f1 += tsm, e1 += tsm)
			{
				for (f2 = m_h*d, e2 = tmh - m_h*d; e2 <= 43200; f2 += tmh, e2 += tmh)
				{
					if (e1<f2 || e2<f1)continue;
					else
					{
						for (f3 = h_s*d, e3 = ths - h_s*d; e3 <= 43200; f3 += ths, e3 += ths)
						{
							if (e1<f3 || e3<f1)
								continue;
							else if (e2<f3 || e3<f2)
								continue;
							else
							{
								op = max(max(f1, f2), max(f2, f3));
								ed = min(min(e1, e2), min(e2, e3));
								result += (ed - op);
							}
						}
					}
				}
			}
			printf("%.3lf\n", result / 432);
		}
	}
	return 0;
}