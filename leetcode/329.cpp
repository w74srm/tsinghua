#include<bits/stdc++.h>
using namespace std;



int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


    int dfs(vector<vector<int>> &matrix, int row, int column, vector<vector<int>> &memo)
    {
        if(memo[row][column] != 0) return memo[row][column];
        memo[row][column]++;
        for(int i = 0; i < 4; i++)
        {
            int newRow = row + dirs[i][0], newColumn = column + dirs[i][1];
            if(newRow >= 0 && newRow < matrix.size() && newColumn >= 0 && newColumn < matrix[0].size() && matrix[newRow][newColumn] > matrix[row][column])
            {
                memo[row][column] = max(memo[row][column], dfs(matrix, newRow, newColumn, memo) + 1);
            }
        }
        return memo[row][column];
    }


int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    vector<vector<int>> memo(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    if(n == 0 || m == 0) cout << 0 << endl;
    else
    {
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                ans = max(ans, dfs(matrix, i, j, memo));
            }
        }
        cout << ans << endl;
    }

}