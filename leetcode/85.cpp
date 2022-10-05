#include<bits/stdc++.h>
using namespace std;


int maximalRectangle(vector< vector< char> >& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    if (m==0) return 0;
    vector< vector<int> > left(m, vector<int>(n, 0));
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if (matrix[i][j] == '1') left[i][j] = (j == 0? 0 : left[i][j-1]) + 1;
        }
    }

    int ret = 0;
    for (int j = 0; j<n;j++){
        vector<int> up(m, 0), down(m, 0);

        stack<int> stk;
        for(int i = 0;i<m;i++){
            while(!stk.empty() && left[stk.top()][j] >= left[i][j]){
                stk.pop();
            }
            up[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for(int i = m-1;i>=0;i--){
            while(!stk.empty() && left[stk.top()][j] >= left[i][j]){
                stk.pop();
            }
            down[i] = stk.empty() ? m : stk.top();
            stk.push(i);
        }
        for (int i = 0; i < m; i++) {
            int height = down[i] - up[i] - 1;
            int area = height * left[i][j];
            ret = max(ret, area);
        }
    }
    return ret;
}


int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char> > matrix;
    for (int i = 0; i < m; i++){
        vector<char> temp;
        for (int j = 0; j < n; j++){
            char c;
            cin >> c;
            temp.push_back(c);
        }
        matrix.push_back(temp);
    }
    int r = maximalRectangle(matrix);
    cout << r << endl;
    return 0;
}