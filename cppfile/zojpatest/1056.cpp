#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node
{
    int weight, index, index0, rank;
};

bool cmp(node a, node b)
{
    return a.index0<b.index0;
}

int main()
{
    int np, ng, temp;
    cin>>np>>ng;
    vector<int> w(np);
    vector<node> v(np);
    for (int i = 0; i<np;i++)
    {
        cin>>w[i];
    }
    for(int i=0; i <np;i++)
    {
        cin>>temp;
        v[i].weight = w[temp];
        v[i].index = i;
        v[i].index0 = temp;
    }
    queue<node> q;
    for(int i = 0;i<np;i++)
    {
        q.push(v[i]);
    }
    while(!q.empty())
    {
        int size = q.size();
        if(size == 1){
            node last = q.front();
            v[last.index].rank = 1;
            break;
        }
        int group = size/ng;
        if(size % ng != 0)
        {
            group += 1;
        }
        node maxnode;
        int maxn = -1, cnt = 0;
        for(int i = 0; i<size; i++)
        {
            node last = q.front();
            v[last.index].rank = group + 1;
            q.pop();
            cnt++;
            if(last.weight > maxn)
            {
                maxn = last.weight;
                maxnode = last;
            }
            if(cnt == ng || i==size-1)
            {
                cnt = 0;
                maxn = -1;
                q.push(maxnode);
            }
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < np; i++){
        if(i != 0) cout<<' ';
        cout << v[i].rank;
    }

    return 0;
}

