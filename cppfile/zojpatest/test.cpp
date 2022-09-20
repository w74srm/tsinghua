#include<iostream>
using namespace std;

int fac(int n)
{
    if (n!=1){
        return n*fac(n-1);
    }
    else{
        return 1;
    }
}

int main()
{
    int n = 0;
    cin >> n;
    if (n>0 && n<=8) cout<<fac(n)<<endl;
    else cout<<"error"<<endl;
    system("pause");
    return 0;
}