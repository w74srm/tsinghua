#include<iostream>
using namespace std;

int main(){
	int s[100],n,n1,m,count,flag=0,i=0;
	while(cin>>n){
		if(n==0) break;
		count=0;
		flag=0;
		for( i=0;i<n;i++)
			cin>>s[i];
		n1=n;
		while(1){
			n1=n;
			m=s[n-1]/2;
			while(n1--){
				if(n1==0)
					break;
				s[n1]/=2;
				s[n1]+=s[n1-1]/2;
			}
			s[0]/=2;
			s[0]+=m;
			for(i=0;i<n;i++)
				if(s[i]%2==1)
					s[i]++;
			count++;
			flag=0;
			for(i=0;i<n-1;i++)
				if(s[i]==s[i+1])
					flag++;
			if(flag==n-1){
				cout<<count<<" "<<s[0]<<endl;
				break;
			}
		}
	}
return 0;
}