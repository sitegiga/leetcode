class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> visited;
        queue<string> q;
        vector<string> res;
        q.push(s);
        visited.insert(s);
        bool found = false;

        while (!q.empty()) {
            string cur = q.front(); q.pop();
            if (isValid(cur)) {
                res.push_back(cur);
                found = true;
            }
            if (found) continue;
            for (int i = 0; i < cur.size(); i++) {
                if (cur[i] != '(' && cur[i] != ')') continue;
                string next = cur.substr(0, i) + cur.substr(i + 1);
                if (!visited.count(next)) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }
        return res;
    }

    bool isValid(string s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }
};
