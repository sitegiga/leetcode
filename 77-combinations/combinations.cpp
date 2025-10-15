class Solution {
public:
    vector<vector<int>> res;
    void dfs(int start, int k, vector<int>& cur, int n) {
        if (k == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = start; i <= n - k + 1; ++i) {
            cur.push_back(i);
            dfs(i+1, k-1, cur, n);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        dfs(1, k, cur, n);
        return res;
    }
};
