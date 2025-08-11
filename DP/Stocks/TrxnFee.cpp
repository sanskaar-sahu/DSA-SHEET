class Solution {
public:
    int tabulate(vector<int>& prices , int fee){
            int n = prices.size();
        vector<vector<int>>dp(n+1 , vector<int>(2 , 0));
        for(int i = n-1 ; i>= 0 ; i--){
            int profit = 0;
            for(int buy = 0; buy <= 1 ; buy++){
                if(buy){
                    profit = max(
                        -prices[i] + dp[i+1][0] , 
                        0 + dp[i+1][1]
                    );
                }else{
                    profit = max(
                        (prices[i] - fee) + dp[i+1][1],
                        0 + dp[i+1][0]
                    );
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int>curr(2 , 0);
        vector<int>next(2,0);
        for(int i = n-1 ; i>= 0 ; i--){
            int profit = 0;
            for(int buy = 0; buy <= 1 ; buy++){
                if(buy){
                    profit = max(
                        -prices[i] + next[0] , 
                        0 + next[1]
                    );
                }else{
                    profit = max(
                        (prices[i] - fee) + next[1],
                        0 + next[0]
                    );
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
};