class Solution {
public:
   
    int trap(vector<int>& height) {
       int n = height.size();
       vector<int>prefix(n);
       vector<int>suffix(n);
       prefix[0] = height[0];
       suffix[n-1] = height[n-1];

       for(int i = 1 ; i < n ; i++){
           prefix[i] = max(prefix[i-1] , height[i]);
           suffix[n-i -1 ] = max(suffix[n - i],height[n-i-1]);
       }

       int total = 0;

       for(int i = 0 ; i < n ; i++){
          int trap = min(prefix[i] , suffix[i]) - height[i];
          total+=trap;
       }

       return total;
    }
};