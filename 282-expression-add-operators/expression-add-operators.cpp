class Solution {
public:
    vector<string> res;
    void dfs(string num, int target, int pos, long cur, long prev, string path) {
        if (pos == num.size()) {
            if (cur == target) res.push_back(path);
            return;
        }
        for (int i = pos; i < num.size(); i++) {
            if (i > pos && num[pos] == '0') break;
            string s = num.substr(pos, i - pos + 1);
            long n = stol(s);
            if (pos == 0) dfs(num, target, i + 1, n, n, s);
            else {
                dfs(num, target, i + 1, cur + n, n, path + "+" + s);
                dfs(num, target, i + 1, cur - n, -n, path + "-" + s);
                dfs(num, target, i + 1, cur - prev + prev * n, prev * n, path + "*" + s);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        dfs(num, target, 0, 0, 0, "");
        return res;
    }
};
