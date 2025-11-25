class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;

        // If k is very large → unlimited transactions
        if(k >= n/2){
            int profit = 0;
            for(int i = 1; i < n; i++){
                if(prices[i] > prices[i-1])
                    profit += prices[i] - prices[i-1];
            }
            return profit;
        }

        // DP table: dp[tx][day]
        vector<vector<int>> dp(k+1, vector<int>(n, 0));

        for(int tx = 1; tx <= k; tx++){
            int maxDiff = -prices[0]; // best (dp[tx-1][d] - price[d])
            for(int day = 1; day < n; day++){
                
                dp[tx][day] = max(dp[tx][day-1], prices[day] + maxDiff);
                
                maxDiff = max(maxDiff, dp[tx-1][day] - prices[day]);
            }
        }

        return dp[k][n-1];
    }
};
