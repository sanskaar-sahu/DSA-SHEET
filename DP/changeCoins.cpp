class Solution {
public:

    int changeCoin(int idx, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        // Base Case
        if (idx == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            return 1e9; // large number to represent impossible
        }

        if (dp[idx][amount] != -1) return dp[idx][amount];

        // Not pick
        int notpick = changeCoin(idx - 1, coins, amount, dp);

        // Pick (only if coin value <= amount)
        int pick = 1e9;
        if (coins[idx] <= amount)
            pick = 1 + changeCoin(idx, coins, amount - coins[idx], dp);

        return dp[idx][amount] = min(pick, notpick);
    }

    //Tabulation method

    int tabulate(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));

        // Base case: only using first coin
        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0)
                dp[0][j] = j / coins[0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                // Not pick
                int notpick = dp[i - 1][j];

                // Pick (if possible)
                int pick = 1e9;
                if (coins[i] <= j)
                    pick = 1 + dp[i][j - coins[i]];

                dp[i][j] = min(pick, notpick);
            }
        }

        int ans = dp[n - 1][amount];
        return (ans >= 1e9) ? -1 : ans;
        
    }

        int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

        // Base case: using only first coin
        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0)
                prev[j] = j / coins[0];
            else
                prev[j] = 1e9; // important missing line
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                int notpick = prev[j];
                int pick = 1e9;
                if (coins[i] <= j)
                    pick = 1 + curr[j - coins[i]];
                curr[j] = min(pick, notpick);
            }
            prev = curr;
        }

        int ans = prev[amount];
        return (ans >= 1e9) ? -1 : ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        return tabulate(coins, amount);
    }
};