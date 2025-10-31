class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        vector<int> hold(n, 0), sold(n, 0), rest(n, 0);
        hold[0] = -prices[0];
        for (int i = 1; i < n; i++) {
            hold[i] = max(hold[i-1], rest[i-1] - prices[i]);
            sold[i] = hold[i-1] + prices[i];
            rest[i] = max(rest[i-1], sold[i-1]);
        }
        return max(sold[n-1], rest[n-1]);
    }
};
