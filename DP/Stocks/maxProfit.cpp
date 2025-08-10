class Solution {
public:
    int maxProfit(vector<int>& prices) {
       if(prices.size() < 2) return 0;
       int mini = prices[0];
       int next = prices[1];
       int profit = 0;
       if(mini < next && prices.size() <= 2){
         profit = next - mini;
         return profit;
       }

       for(int i = 1 ; i < prices.size() ; i++){
          if(prices[i] <= mini) mini = prices[i];
          profit = max(profit , prices[i] - mini);
       }

       return profit;
    }
};