class Solution
{
public:
    int res(int idx, vector<int> &prices, int buy, vector<vector<int>> &dp)
    { // buy act as a flag
        if (idx == prices.size())
            return 0;
        int profit = 0;

        if (dp[idx][buy] != -1)
            return dp[idx][buy];
        if (buy)
        { // flagged as true i.e u can buy
            profit = max(
                -prices[idx] + res(idx + 1, prices, 0, dp), // you bought
                0 + res(idx + 1, prices, 1, dp)             // u didnt bought
            );
        }
        else
        {
            profit = max(
                prices[idx] + res(idx + 1, prices, 1, dp), // you sold now u r allowed to buy
                res(idx + 1, prices, 0, dp));              // you didnt sold not allow to bu
        }

        return dp[idx][buy] = profit;
    }

    int tabulate(vector<int> &prices){
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0)); // +1 for base case

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++){
                if (buy){
                    dp[i][buy] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                }
                else {
                    dp[i][buy] = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
                }
            }
        }
        return dp[0][1]; // start at day 0 with buy allowed
    }

    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;
        int mini = prices[0];
        int next = prices[1];
        if (mini < next && prices.size() < 3)
            return next - mini;

        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));

        return res(0, prices, 1, dp);
    }
};