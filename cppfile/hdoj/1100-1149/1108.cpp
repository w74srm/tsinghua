#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdlib.h>
//#define DEBUG
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
ll gcd(int a,int b) {
    return b==0? a : gcd(b,a%b);
}
int a,b;
int main() {
    while(cin>>a>>b) {
        cout<<a*b/gcd(a,b)<<endl;
 
 
    }
    
 
    return 0;
}