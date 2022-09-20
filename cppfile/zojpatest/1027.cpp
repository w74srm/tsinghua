#include <iostream>
 
using namespace std;
 
void func(int a){
    int b = a/13;
    int c = a%13;
    if(b<10)
        cout<<b;
    else if(b==10)
        cout<<"A";
    else if(b==11)
        cout<<"B";
    else
        cout<<"C";
    if(c<10)
        cout<<c;
    else if(c==10)
        cout<<"A";
    else if(c==11)
        cout<<"B";
    else
        cout<<"C";
}
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
 
    cout<<"#";
    func(a);
    func(b);
    func(c);
    return 0;
}