#include<iostream>
#include<vector>
using namespace std;

const int maxn = 35;
int postorder[maxn],inorder[maxn];
vector<int> levelorder;

int searchinInorder(int start ,int end, int n){
    for(int i=start;i<=end;i++){
        if(inorder[i]==n) return i;
    }
}

void trans(int start,int end){
    levelorder.push_back(postorder[end]);
}