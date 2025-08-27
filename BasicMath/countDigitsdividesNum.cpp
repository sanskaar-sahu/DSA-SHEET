class Solution {
public:
    int countDigits(int num) {
        int temp = num;
        int cnt = 0;
        
        while (temp > 0) {
            int digit = temp % 10;
            if (digit != 0 && num % digit == 0) cnt++;
            temp /= 10;
        }
        
        return cnt;
    }
};