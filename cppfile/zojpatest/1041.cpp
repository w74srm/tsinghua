#include<iostream>
using namespace std;

const int maxn = 10010;
const int maxk = 100010;
int record[maxn];
int input[maxk];

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int temp;
        cin>>temp;
        record[temp]++;
        input[i] = temp;
    }
    int flag = 1;
    for(int i=0;i<N;i++){
        if(record[input[i]]==1) {
            cout<<input[i]<<endl;
            flag = 0;
            break;
        }
    }
    if(flag==1) cout<<"None"<<endl;
    return 0;
}