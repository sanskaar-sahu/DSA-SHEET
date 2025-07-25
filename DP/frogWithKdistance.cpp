class Solution {

public:   
    int energy(int idx, vector<int>& heights, int k , vector<int>&dp) {

        if(idx == 0){
            return 0;
        }

        if(dp[idx]!= -1) return dp[idx];

        int minJumps = INT_MAX;
        for (int i = 1; i <= k; i++) {
            if ((idx - i) >= 0) {
                int jump = energy(idx - i, heights, k , dp) + abs(heights[idx] - heights[idx - i]);
                minJumps = min(minJumps, jump);
            }
        }
        return minJumps;
    }
    int frogJump(vector<int>& heights, int k) {
        dp[0] = 0;
        int n = heights.size()
        vector<int>dp(heights.size() + 1 , -1);
        return dp[n-1];
    }
};
