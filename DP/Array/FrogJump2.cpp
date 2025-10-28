class Solution {
public:
    int maxJump(vector<int>& stones) {
          //lets split the path the possible two jumps we can take in other case the probablity 
          //of having larger value would increase we try the greedy way to keep it as small 
          //since its in increasing order;
          int n = stones.size();
          int res = abs(stones[1] - stones[0]);

          //even steps(forward path)
          for(int i = 2 ; i < n ; i = i + 2){
             if(i- 2 < 0) continue;
             res = max(res , abs(stones[i] - stones[i-2]));
          }

          //Odd steps (backward path)
          for(int i = 3 ; i < n ; i = i + 2){
            if(i - 2 < 0) continue; 
             res = max(res , abs(stones[i] - stones[i -2]));
          }

          return  res;

    }
};