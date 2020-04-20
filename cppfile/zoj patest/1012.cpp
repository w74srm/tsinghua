#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
const int maxn = 200200;
struct Node{
	int id,cs,ms,es,as;
	int cth,mth,eth,ath;
	int fth;
	char ff;
}cur[maxn];
map <int,int> mp;
bool cmp(Node a,Node b)
{
	return a.cs>b.cs;
}
bool mmp(Node a,Node b)
{
	return a.ms>b.ms;
}
bool emp(Node a,Node b)
{
	return a.es>b.es;
}
bool amp(Node a,Node b)
{
	return a.as>b.as;
}
int main(void)
{
	int n,m,x,i;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++) 
	scanf("%d%d%d%d",&cur[i].id,&cur[i].cs,&cur[i].ms,&cur[i].es),cur[i].as=(cur[i].cs+cur[i].es+cur[i].ms)/3;
	sort(cur,cur+n,cmp);
	cur[0].cth=1;
	for(i=1;i<n;i++)
	if(cur[i].cs==cur[i-1].cs) cur[i].cth=cur[i-1].cth;
	else cur[i].cth=i+1;
	
	sort(cur,cur+n,mmp);
	cur[0].mth=1;
	for(i=1;i<n;i++)
	if(cur[i].ms==cur[i-1].ms) cur[i].mth=cur[i-1].mth;
	else cur[i].mth=i+1;
	
	sort(cur,cur+n,emp);
	cur[0].eth=1;
	for(i=1;i<n;i++)
	if(cur[i].es==cur[i-1].es) cur[i].eth=cur[i-1].eth;
	else cur[i].eth=i+1;
	
	sort(cur,cur+n,amp);
	cur[0].ath=1;
	for(i=1;i<n;i++)
	if(cur[i].as==cur[i-1].as) cur[i].ath=cur[i-1].ath;
	else cur[i].ath=i+1;
	
	for(i=0;i<n;i++){
		int tt=min(min(cur[i].ath,cur[i].cth),min(cur[i].eth,cur[i].mth));
		if(cur[i].ath==tt){
			cur[i].fth=cur[i].ath;
			cur[i].ff='A';
		}
		else if(tt==cur[i].cth){
			cur[i].fth=cur[i].cth;
			cur[i].ff='C';
		}
		else if(tt==cur[i].mth){
			cur[i].fth=cur[i].mth;
			cur[i].ff='M';
		}
		else if(tt==cur[i].eth){
			cur[i].fth=cur[i].eth;
			cur[i].ff='E';
		}
		
		mp[cur[i].id]=i+1;
	}
	for(i=0;i<m;i++){
		scanf("%d",&x);
		x=mp[x];
		if(x>0){
			x--;
			printf("%d %c\n",cur[x].fth,cur[x].ff);
		}
		else{
			printf("N/A\n");
		}
	}
	return 0;
}