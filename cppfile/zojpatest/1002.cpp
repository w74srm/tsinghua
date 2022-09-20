#include<iostream>
#include<iomanip>
using namespace std;
 
int main() {
	int a = 0;
	float p[1001] = { 0 }, q[1001] = { 0 }, s[1001] = { 0 }, k = 0, num = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a;
		cin >> p[a];
	}
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a;
		cin >> q[a];
	}
	for (int i = 0; i<1001; i++) {
		if (p[i] != 0 && q[i] != 0) {
			s[i] = p[i] + q[i];
			if (s[i])k++;
			continue;
		}
		if (p[i] != 0) {
			s[i] = p[i];
			k++;
			continue;
		}
		if (q[i] != 0) {
			s[i] = q[i];
			k++;
			continue;
		}
	}
	cout << k;
	for (int i = 1000; i >= 0; i--) {
		if (s[i] != 0) {
			cout << " " << i << " ";
			cout << setiosflags(ios::fixed);
			cout << setprecision(1) << s[i];
		}
	}
	cout << endl;
	return 0;
}