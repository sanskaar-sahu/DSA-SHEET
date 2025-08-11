class Solution {
public:
    
    //recursion 
    int fn(int i , int buy , int trans , vector<int>& prices , int n){
        if(i== n || trans == 0) return 0;
        
        int profit = 0;
        if(buy){
            profit = max(
                -prices[i] + fn(i+1 , 0 , trans , prices , n) , //bought now no more buy
                0 + fn(i+1 , 1 , trans , prices , n)
            );
        }else{
            profit = max(
                prices[i] + fn(i+1 , 1 , trans -1  , prices , n) , //sold now can buy
                0 + fn(i+1 , 0 , trans , prices , n)
            );  
        }

        return profit;
    }
    
    //memoization 
    int fn(int i , int buy , int trans , vector<int>& prices , int n , vector<vector<vector<int>>>&dp){
        if(i== n || trans == 0) return 0;

        if(dp[i][buy][trans]!= -1) return dp[i][buy][trans];
        
        int profit = 0;
        if(buy){
            profit = max(
                -prices[i] + fn(i+1 , 0 , trans , prices , n, dp) , //bought now no more buy
                0 + fn(i+1 , 1 , trans , prices , n,dp)
            );
        }else{
            profit = max(
                prices[i] + fn(i+1 , 1 , trans -1  , prices , n,dp) , //sold now can buy
                0 + fn(i+1 , 0 , trans , prices , n,dp)
            );  
        }

        return dp[i][buy][trans] =  profit;
    }

    //tabulation
    int tabulate(int k, vector<int>& prices){
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for(int i = n-1 ; i>= 0 ; i--){
            int profit = 0;
            for(int buy = 0 ; buy <= 1 ; buy++){
                for(int trans = 1 ; trans<=k ; trans++){
                    if(buy){
                        profit = max(
                            -prices[i] + dp[i+1][0][trans], 
                             0 + dp[i+1][1][trans]);
                    }else{
                         profit = max(
                            prices[i] + dp[i+1][1][trans -1] , //sold
                            0 + dp[i+1][0][trans]);  
                    }

                    dp[i][buy][trans] = profit;
                }
            }
        }
        return dp[0][1][k];
    }

    int spaceX(vector<int>& prices){
        int n = prices.size();
        vector<int>curr(2 , 0);
        vector<int>next(2 , 0);
        vector<int>next2(2 , 0);

        for(int i = n-1 ; i>= 0 ; i--){
            int profit = 0;
            for(int buy = 0 ; buy <= 1 ; buy++){
                    if(buy){
                        profit = max(
                            -prices[i] + next[0], 
                             0 + next[1]);
                    }else{
                         profit = max(
                            prices[i] + next2[1] , //sold
                            0 + next[0]);  
                    }
                    curr[buy] = profit;
            }
            next2 = next;
            next = curr;
        }
        return next[1];
    }



    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        return tabulate(k , prices);
    }
};