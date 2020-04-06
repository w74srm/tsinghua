#include<cstdio>
using namespace std;
int MaxBlock;
char map[5][5];
 
bool canPlace(int row , int col) {
	int i , j;
	for(i=col-1;i>=0;i--) {
		if(map[row][i] == 'X') {
			break;
		}
		if(map[row][i] == 'N') {
			return false;
		}
	}
	for(j=row-1;j>=0;j--) {
		if(map[j][col]=='X') {
			break;
		} 
		if(map[j][col]=='N') {
			return false;
		}
	}
	return true;
}
 
void DFS(int i , int num , int n) {
	int row, col;
	if(i == (n * n)) {
		if(num > MaxBlock) {
			MaxBlock = num;
		}
		return;
	}
	row = i / n;
	col = i % n;
	if(map[row][col]=='.' && canPlace(row,col)) {
		map[row][col] = 'N';
		DFS(i+1,num+1,n);
		map[row][col] = '.';
	}
	DFS(i+1,num,n);
}
 
int main() {
	int n , i;
	while(scanf("%d",&n) , n) {
		for(i=0;i<n;i++) {
			scanf("%s",map[i]);
		}
		MaxBlock = 0;
		DFS(0 , 0 , n);
		printf("%d\n",MaxBlock);
	}
	return 0;
}