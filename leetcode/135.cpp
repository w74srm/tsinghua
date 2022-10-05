#include<bits/stdc++.h>
using namespace std;


int candy(vector<int>& ratings)
{
    int res = 1;
    int pre = 1;
    int desc = 0, insc = 1;
    for(int i= 1; i < ratings.size(); i++){
        if (ratings[i] >= ratings[i-1]){
            desc = 0;
            pre = ratings[i] == ratings[i-1] ? 1 : pre + 1;
            res += pre;
            insc = pre;
        }
        else{
            desc += 1;
            if(desc == insc){
                desc += 1;
            }
            res += desc;
            pre = 1;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ratings(n, 0);
    for(int i=0; i<n; i++)
    {
        cin >> ratings[i];
    }
    int result = candy(ratings);
    cout << result << endl;
    return 0;
}