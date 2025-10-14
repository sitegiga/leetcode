class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n, 1), num;
        for (int i = 1; i < n; i++) fact[i] = fact[i-1] * i;
        for (int i = 1; i <= n; i++) num.push_back(i);
        k--;
        string ans = "";
        for (int i = n - 1; i >= 0; i--) {
            int idx = k / fact[i];
            ans += to_string(num[idx]);
            num.erase(num.begin() + idx);
            k %= fact[i];
        }
        return ans;
    }
};
