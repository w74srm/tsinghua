#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;
int n, k;
vector<int> line;
 
struct Customer{
    int arrive;
    int time;
};
bool compare(Customer c1,Customer c2){
    return c1.arrive<c2.arrive;
}
int timeToInt(string time){
    int h = atoi(time.substr(0,2).data());
    int m = atoi(time.substr(3,2).data());
    int s = atoi(time.substr(6,2).data());
    return h*3600+m*60+s;
}
int minLine(){
    int minline=0;
    for(int j=1;j<k;j++){
        if(line[minline]>line[j])
            minline=j;
    }
    return minline;
}
int main()
{
    cin>>n>>k;
    int i;
    vector<Customer> c;
    vector<int> linetime;
    if(n<=0||k<=0){
        printf("%.1f", 0.0);
        return 0;
    }
 
    for(i=0;i<n;i++){
        Customer cust;
        string arrivestring;
        int arriveint;
        cin>>arrivestring>>cust.time;
        arriveint = timeToInt(arrivestring);
        if(arriveint<=61200){
            cust.arrive = arriveint;
            c.push_back(cust);
        }
    }
 
    int cnt = c.size();
    sort(c.begin(),c.end(),compare);
 
    for(i=0;i<k;i++){
        line.push_back(28800);
    }
 
    int waittime=0;
 
    for(i=0;i<cnt;i++){
        int minline = minLine();
        if(c[i].arrive<line[minline]){
            waittime+=line[minline]-c[i].arrive;
            line[minline]+=c[i].time*60;
        }else{
            line[minline]=c[i].arrive+c[i].time*60;
        }
    }
 
    printf("%.1f", waittime/(cnt*60.0));
 
    return 0;
}