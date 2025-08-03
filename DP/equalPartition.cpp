class Solution {

public:
   
    bool recurr(int idx , int req,vector<int>&nums){
         if (req == 0) return true;  // found subset with required sum
        if (idx == 0) return nums[0] == req;  // check if first element alone can make the sum

        bool pick = false;
        if (nums[idx] <= req) {
            pick = recurr(idx - 1, req - nums[idx], nums);
        }

        bool notpick = recurr(idx - 1, req, nums);  // leave the number

        return pick || notpick;
          
    }

    bool memo(int idx, int req, vector<int>& nums, vector<vector<int>>& dp) {
        if (req == 0) return true;
        if (idx == 0) return nums[0] == req;

        if (dp[idx][req] != -1) return dp[idx][req];

        bool pick = false;
        if (nums[idx] <= req) {
            pick = memo(idx - 1, req - nums[idx], nums, dp);
        }

        bool notpick = memo(idx - 1, req, nums, dp);

        return dp[idx][req] = pick || notpick;
    }


     
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto it : nums){
            sum+=it;
        }
        if(sum%2!= 0) return false;

        int req = sum/2;

        vector<vector<bool>>dp(n , vector<bool>(req+1 , false));

        // You can always make sum = 0 by picking nothing
        for (int i = 0; i < n; i++) dp[i][0] = true;

        // First element base case
        if (nums[0] <= req) dp[0][nums[0]] = true;
        
            for (int i = 1; i < n; i++) {
            for (int j = 1; j <= req; j++) {
                bool notpick = dp[i - 1][j];
                bool pick = false;

                if (nums[i] <= j) {
                    pick = dp[i - 1][j - nums[i]];
                }

                dp[i][j] = pick || notpick;
            }
        }

        return dp[n - 1][req];
    }
};