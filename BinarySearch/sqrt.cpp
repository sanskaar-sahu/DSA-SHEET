class Solution {
public:
    int mySqrt(int x) {
         
         if(x == 1) return 1;
           
        int low = 1;
        int high = x /2 + 1;

        while(low <= high){
            int mid = low + (high - low)/2;
            long long sq = 1LL * mid * mid;
            if(x == sq) return mid;

            if(sq > x ) high = mid -1;
            else low = mid + 1;
        }
      return high;
    }
};