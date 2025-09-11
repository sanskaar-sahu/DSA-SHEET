class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while(i < n && s[i] == ' ') i++;  // skip spaces
        
        int sign = 1;
        if(i < n && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-') sign = -1;
            i++;
        }
        
        long num = 0;
        while(i < n && isdigit(s[i])) {
            num = num*10 + (s[i]-'0');
            if(sign == 1 && num > INT_MAX) return INT_MAX;
            if(sign == -1 && -num < INT_MIN) return INT_MIN;
            i++;
        }
        
        return sign * (int)num;
    }
};