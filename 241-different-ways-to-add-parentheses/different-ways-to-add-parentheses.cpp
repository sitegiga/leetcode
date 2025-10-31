class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> res;
        for (int i = 0; i < exp.size(); i++) {
            if (ispunct(exp[i])) {
                auto left = diffWaysToCompute(exp.substr(0, i));
                auto right = diffWaysToCompute(exp.substr(i + 1));
                for (int a : left)
                    for (int b : right)
                        res.push_back(exp[i] == '+' ? a + b : exp[i] == '-' ? a - b : a * b);
            }
        }
        return res.empty() ? vector<int>{stoi(exp)} : res;
    }
};
