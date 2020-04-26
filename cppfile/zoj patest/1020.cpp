#include <iostream>
#include <vector>
using namespace std;
 
int n;
vector<int> level[31];
int num[31]={0};
int post[30]={0}, in[30]={0};
 
 
void pre(int post1,int post2,int in1,int in2,int lev){
    if(post1>post2||in1>in2||lev>n)
        return;
    level[lev].push_back(post[post2]);
    num[lev]++;
    int i;
    for(i=in1;i<=in2;i++){
        if(in[i]==post[post2])
            break;
    }
    pre(post1,post1+i-in1-1,in1,in1+i-in1-1,lev+1);
    pre(post1+i-in1,post2-1,i+1,in2,lev+1);
}
 
int main()
{
    int i;
    cin>>n;
 
    for(i=0;i<n;i++)
        cin>>post[i];
    for(i=0;i<n;i++)
        cin>>in[i];
 
    pre(0,n-1,0,n-1,1);
 
    cout<<level[1][0];
    for(i=2;i<31;i++){
        for(int j=0;j<num[i];j++){
            if(level[i][j]==0)
                continue;
            cout<<" "<<level[i][j];
        }
    }
    return 0;
}