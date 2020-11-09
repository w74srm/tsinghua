#include <cstdio>
#include <vector>
using namespace std;

struct node{
    node* left;
    node* right;
    int value;
    node(){
        int value=-1;
        left=right=NULL;
    }
};

int N;
vector<int> preorder;

node* insert1(node* &x,int a){
    if(x==NULL){
        x=new node();
        x->value=a;
    }
    else{
        if(a<x->value) x->left=insert1(x->left,a);
        else x->right=insert1(x->right,a);
    }
    return x;
}

node* insert2(node* &x,int a){
    if(x==NULL){
        x=new node();
        x->value=a;
    }
    else{
        if(a>=x->value) x->left=insert2(x->left,a);
        else x->right=insert2(x->right,a);
    }
    return x;
}

/*根据BST的规则建树*/
node* buildTree1(node* root,int index){
    while(index<N){
        insert1(root,preorder[index]);
        index++;
    }
    return root;
}

node* buildTree2(node* root,int index){
    while(index<N){
        insert2(root,preorder[index]);
        index++;
    }
    return root;
}

int flag=1,cnt=0;
void preOrder(node* root){
    if(cnt<N&&root->value!=preorder[cnt]) {
        flag=0;
    };
    cnt++;
    if(root->left!=NULL) preOrder(root->left);
    if(root->right!=NULL) preOrder(root->right);
}

int flag1=0;
void postOrder(node* root){
    if(root->left!=NULL) postOrder(root->left);
    if(root->right!=NULL) postOrder(root->right);
    if(flag1==0) { 
        printf("%d",root->value);
        flag1++;
    }
    else printf(" %d",root->value);
}


int main(){
    scanf("%d",&N);

    node* root1=new node();
    node* root2=new node();
    preorder.resize(N);

    for(int i=0;i<N;i++){
        scanf("%d",&preorder[i]);
        if(i==0) {
            root1->value=preorder[0];
            root2->value=preorder[0];
        }
    }

    buildTree1(root1,1);
    preOrder(root1);
    if(flag){
        printf("YES\n");
        postOrder(root1);
    }
    else{
        flag=1,cnt=0;
        buildTree2(root2,1);
        preOrder(root2);
        if(flag){
            printf("YES\n");
            postOrder(root2);
        }
        else printf("NO\n");
    }

    return 0;
}