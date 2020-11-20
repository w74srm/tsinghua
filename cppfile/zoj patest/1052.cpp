#include <cstdio>
#include <algorithm>
#define SIZE 100005
 
using namespace std;
 
struct Node{
	int key;
	int Next;
};
 
bool cmp(const Node &n1,const Node &n2){
	return n1.key < n2.key;
}
 
Node records[SIZE];
Node sortedlist[SIZE];
 
int main()
{
	int N,HEAD;
	scanf("%d %d",&N,&HEAD);
	int index,i =0;
	for(;i<N;i++){
		scanf("%d",&index);
		scanf("%d %d",&records[index].key,&records[index].Next);
	}
	int j=0;
	index = HEAD;
	if(index == -1){
		printf("0 -1\n");
		return 0;
	}
	while(index != -1){
		sortedlist[j].Next=index;
		sortedlist[j].key = records[index].key;
		index = records[index].Next;
		j++;
	}
	sort(sortedlist,sortedlist+j,cmp);
	printf("%d %05d\n",j,sortedlist[0].Next);
	for(i=0;i<j-1;i++){
		printf("%05d %d %05d\n",sortedlist[i].Next,sortedlist[i].key,sortedlist[i+1].Next);
	}
	printf("%05d %d -1\n",sortedlist[i].Next,sortedlist[i].key);
	return 0;
}