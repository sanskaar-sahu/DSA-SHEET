class Solution {
public:
   int digCnt(int x){
    int cnt = 0;
    while(x > 0){
        cnt++;
        x/=10;
    }
    return cnt;
   }
    int reverse(int x) {
      long long num = 0;  // use long long to detect overflow
        int sign = (x < 0) ? -1 : 1;
        x = abs(x);

        while (x > 0) {
            int mod = x % 10;
            num = num * 10 + mod; // shift left and add digit
            x /= 10;
        }

        num *= sign;
        return num;
    }
};