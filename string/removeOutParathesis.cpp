class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string ans = "";

        for (char c : s) {
            if (c == '(') {
                if (cnt > 0) ans += c;  // only add if not outermost
                cnt++;
            } else {
                cnt--;
                if (cnt > 0) ans += c;  // only add if not outermost
            }
        }

        return ans;
    }
};