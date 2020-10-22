#include<bits/stdc++.h>
using namespace std;

int main(){
    int next[100000];
    char data[100000];
    bool h[100000];
    int p1, p2, n;
    cin >> p1 >> p2 >> n;

    while(n --){
        int address;
        cin >> address;
        cin >> data[address] >> next[address];
    }  

    while(p1 != -1){
        h[p1] = true;
        p1 = next[p1];
    }

    while(p2 != -1){
        if(h[p2] == true){
            printf("%05d", p2);
            return 0;
        }
        p2 = next[p2];
    }
    printf("-1");
    return 0;
}
