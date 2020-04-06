#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main()
{
    int i;
    string a,s;
    while(cin>>a && a!="ENDOFINPUT")
    { 
		getchar();
		getline(cin,s);
		cin>>a;
		for(i=0;i<s.length();i++)
		{
			if(s[i]>='A'&&s[i]<='Z')
			s[i]=(s[i]-'A'+21)%26+'A';
		}
		cout<<s<<endl;
    }
    return 0;
}