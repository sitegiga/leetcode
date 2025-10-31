class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                res = max(res, dfs(matrix, dp, i, j));
        return res;
    }

    int dfs(vector<vector<int>>& mat, vector<vector<int>>& dp, int i, int j) {
        if (dp[i][j]) return dp[i][j];
        int m = mat.size(), n = mat[0].size();
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int val = 1;
        for (auto& d : dirs) {
            int x = i + d[0], y = j + d[1];
            if (x >= 0 && x < m && y >= 0 && y < n && mat[x][y] > mat[i][j])
                val = max(val, 1 + dfs(mat, dp, x, y));
        }
        return dp[i][j] = val;
    }
};
