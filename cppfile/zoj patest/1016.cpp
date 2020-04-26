#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int cents[24],n;
 
struct Record{
    string name;
    int month;
    int day;
    int hour;
    int minute;
    string status;
};
bool cmp(Record r1, Record r2){
    if(r1.name.compare(r2.name)==0){
        if(r1.day<r2.day)
            return 1;
        else if(r1.day>r2.day)
            return 0;
        else{
            if(r1.hour<r2.hour)
                return 1;
            else if(r1.hour>r2.hour)
                return 0;
            else{
                if(r1.minute<r2.minute)
                    return 1;
                else
                    return 0;
            }
        }
    }else if(r1.name.compare(r2.name)>0){
        return 0;
    }else{
        return 1;
    }
}
int tim(Record r1,Record r2){
    return r2.day*24*60+r2.hour*60+r2.minute-r1.day*24*60-r1.hour*60-r1.minute;
}
int callAllDay(){
    int t=0;
    for(int i=0;i<24;i++){
        t+=cents[i]*60;
    }
    return t;
}
int callNtoM(int n,int m){
    int t=0;
    for(int i=n;i<m;i++){
        t+=cents[i]*60;
    }
    return t;
}
double mone(Record r1,Record r2){
    int total=0;
    if(r1.day<r2.day){
        int i=r2.day-r1.day;
        total+=(i-1)*callAllDay();
        total+=callNtoM(r1.hour+1,24);
        total+=(60-r1.minute)*cents[r1.hour];
 
        total+=callNtoM(0,r2.hour);
        total+=r2.minute*cents[r2.hour];
    }else{
        if(r2.hour>r1.hour){
            total+=callNtoM(r1.hour+1,r2.hour);
            total+=(60-r1.minute)*cents[r1.hour]+r2.minute*cents[r2.hour];
        }else{
            total+=(r2.minute-r1.minute)*cents[r1.hour];
        }
    }
    return total/100.0;
}
int main()
{
    int i;
    vector<Record> r;
    for(i=0;i<24;i++)
        cin>>cents[i];
 
    cin>>n;
    for(i=0;i<n;i++){
        string n,s;
        int mo,d,h,mi;
        cin>>n;
        scanf("%d:%d:%d:%d",&mo,&d,&h,&mi);
        cin>>s;
        Record re;
        re.name=n;
        re.day=d;
        re.hour=h;
        re.minute=mi;
        re.month=mo;
        re.status=s;
        r.push_back(re);
    }
    sort(r.begin(),r.end(),cmp);
 
    string sn=r[0].name;
    bool valid=0;
 
    for(i=0;i<r.size();i++){
        if(sn!=r[i].name){
            if(valid==1){
                r.erase(r.begin()+i-1);
                i--;
            }
            sn=r[i].name;
            valid=0;
        }
        if(valid==0&&r[i].status=="on-line"){
            valid=1;
        }else if(valid==0&&r[i].status=="off-line"){
            r.erase(r.begin()+i);
            i--;
        }else if(valid==1&&r[i].status=="off-line"){
            valid=0;
        }else if(valid==1&&r[i].status=="on-line"){
            r.erase(r.begin()+i-1);
            i--;
        }
    }
    if(valid==1)
        r.erase(r.begin()+i-1);
 
    sn=r[0].name;
    cout<<sn<<" ";
    printf("%02d",r[0].month);
    cout<<endl;
    double total=0.0;
    for(i=0;i<r.size();i++){
        if(r[i].name!=sn){
            cout<<"Total amount: $";
            printf("%.2f",total);
            cout<<endl;
            sn=r[i].name;
            cout<<sn<<" ";
            printf("%02d",r[i].month);
            cout<<endl;
            total=0.0;
        }
        if(r[i].status=="on-line"){
            printf("%02d:%02d:%02d",r[i].day,r[i].hour,r[i].minute);
            cout<<" ";
        }
        if(r[i].status=="off-line"){
            printf("%02d:%02d:%02d",r[i].day,r[i].hour,r[i].minute);
            int time=tim(r[i-1],r[i]);
            double money=mone(r[i-1],r[i]);
            cout<<" "<<time<<" $";
            printf("%.2f",money);
            cout<<endl;
            total+=money;
        }
    }
    cout<<"Total amount: $";
    printf("%.2f",total);
    return 0;
}