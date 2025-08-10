class Solution {
public:
int res(int idx, int buy, int trans, vector<int>& prices, vector<vector<vector<int>>>& dp) {
    int n = prices.size();
    if (idx == n || trans == 0) return 0;

    if (dp[idx][buy][trans] != -1) return dp[idx][buy][trans];

    int profit = 0;
    if (buy) {
        // Option 1: Buy today
        profit = max(-prices[idx] + res(idx + 1, 0, trans, prices, dp),
                     res(idx + 1, 1, trans, prices, dp)); // Skip buying
    } else {
        // Option 1: Sell today (transaction completed)
        profit = max(prices[idx] + res(idx + 1, 1, trans - 1, prices, dp),
                     res(idx + 1, 0, trans, prices, dp)); // Skip selling
    }
    return dp[idx][buy][trans] = profit;
}
int tabulate(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int trans = 1; trans <= 2; trans++) {
                int profit = 0;
                if (buy) {
                    profit = max(-prices[i] + dp[i + 1][0][trans],
                                 dp[i + 1][1][trans]);
                } else {
                    profit = max(prices[i] + dp[i + 1][1][trans - 1],
                                 dp[i + 1][0][trans]);
                }
                dp[i][buy][trans] = profit;
            }
        }
    }
    return dp[0][1][2];
}

int spaceOpt(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> after(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int trans = 1; trans <= 2; trans++) {
                int profit;
                if (buy) {
                    profit = max(-prices[i] + after[0][trans],
                                 after[1][trans]);
                } else {
                    profit = max(prices[i] + after[1][trans - 1],
                                 after[0][trans]);
                }
                curr[buy][trans] = profit;
            }
        }
        after = curr; // move to next day
    }

    return curr[1][2]; // explicitly from day 0 state
}

                      
    int maxProfit(vector<int>& prices) {
        
        return tabulate(prices);
    }
};