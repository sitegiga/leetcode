class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;
        for (auto& t : tickets)
            graph[t[0]].insert(t[1]);
        vector<string> res;
        dfs("JFK", graph, res);
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(string u, unordered_map<string, multiset<string>>& g, vector<string>& res) {
        while (!g[u].empty()) {
            string v = *g[u].begin();
            g[u].erase(g[u].begin());
            dfs(v, g, res);
        }
        res.push_back(u);
    }
};
