class Solution
{
public:
    // int maxAmount(int idx , int odd ,  vector<int>& nums , int& total){
    //     if(idx == 0 ) return 0;
    //     int maxMoney = INT_MIN;
    //     int houeses= maxAmount(idx - odd , nums , total + nums[idx]);

    //     return max(maxMoney , houses);

    // }

    // Que 198 dp problem

    int recurr(int idx, vector<int> &nums, vector<int> &dp)
    {
        if (idx == 0)
            return nums[idx];
        if (idx < 0)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        // lets take the approach of pick not pick {2, 1 , 1 , 9}

        int pick = nums[idx] + recurr(idx - 2, nums, dp);

        int notpick = recurr(idx - 1, nums, dp);

        return dp[idx] = max(pick, notpick);
    }

    int tabulate(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++)
        {
            int pick = nums[i] + dp[i - 2];
            int notpick = dp[i - 1];
            dp[i] = max(pick, notpick);
        }

        return dp[n - 1];
    }

    int rob(vector<int> &nums)
    {
        return tabulate(nums);
    }
};