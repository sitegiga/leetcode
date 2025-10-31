class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<int> degree(n);
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (degree[i] == 1) q.push(i);

        while (n > 2) {
            int size = q.size();
            n -= size;
            while (size--) {
                int node = q.front(); q.pop();
                for (int nei : graph[node])
                    if (--degree[nei] == 1)
                        q.push(nei);
            }
        }
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front()); q.pop();
        }
        return res;
    }
};
