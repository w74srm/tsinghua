#include <bits/stdc++.h>
using namespace std;
int tree[1005], N;
vector<int> path;
void DFS(int root, bool maxHeap, bool &isHeap)
{                               //对整棵树进行遍历
    if (root > N)               //空结点
        return;                 //直接返回
    path.push_back(tree[root]); //将当前结点压入path中
    if (root * 2 > N)
    {                                         //是叶结点
        for (int i = 0; i < path.size(); ++i) //输出path中所有结点信息
            printf("%s%d", i == 0 ? "" : " ", path[i]);
        puts("");        //换行
        path.pop_back(); //弹出最后一个结点
        return;          //返回
    }
    if ((root * 2 <= N && (maxHeap ^ tree[root] > tree[root * 2])) //判断是否是堆，注意异或操作
        || (root * 2 + 1 <= N && (maxHeap ^ tree[root] > tree[root * 2 + 1])))
        isHeap = false;
    DFS(root * 2 + 1, maxHeap, isHeap); //遍历右子树
    DFS(root * 2, maxHeap, isHeap);     //遍历左子树
    path.pop_back();                    //弹出最后一个结点
}
int main()
{
    scanf("%d", &N);
    bool isHeap = true;
    for (int i = 1; i <= N; ++i)
        scanf("%d", &tree[i]);
    DFS(1, tree[1] > tree[2], isHeap);
    if (isHeap)
        puts(tree[1] > tree[2] ? "Max Heap" : "Min Heap");
    else
        puts("Not Heap");
    return 0;
}
