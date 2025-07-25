class Solution {
  
    int jumps(int idx, vector<int>& stones, vector<int>& dp) {
        if (idx == 0) return 0;
        if (dp[idx] != -1) return dp[idx];

        int mini = INT_MAX;
        for (int i = 1; i <= idx; i++) {
            int cost = jumps(idx - i, stones, dp) + abs(stones[idx] - stones[idx - i]);
            mini = min(mini, cost);
        }

        return dp[idx] = mini;
    }

    int n = stones.size();
    vector<int> dp(n, 0);  // dp[i] = min energy to reach i-th stone
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        int mini = INT_MAX;
        for (int j = 1; j <= i; j++) {
            int jump = dp[i - j] + abs(stones[i] - stones[i - j]);
            mini = min(mini, jump);
        }
        dp[i] = mini;
    }
    return dp[n - 1];

public:
    int maxJump(vector<int>& stones) {
        int minE = jumps(stones.size() -1 , stones);
        return minE;
    }
};