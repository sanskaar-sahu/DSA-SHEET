class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;  // ✅ fixed typo

        string res(s.begin(), s.end());
        res.insert(res.end(), s.begin(), s.end());     // ✅ duplicate s to make res twice

        for(int i = 0 ; i < 2 * s.length(); i++){
            string sub = res.substr(i, goal.length()); // ✅ added semicolon
            if(sub == goal) return true;
        }
        return false;
    }
};
