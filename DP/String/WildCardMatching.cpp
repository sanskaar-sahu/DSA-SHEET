class Solution {
public:
    bool isMatch(int idx1 , int idx2 , string s , string p, vector<vector<int>>& dp){
                // if pattern consumed
        if(idx2 == p.length()) return idx1 == s.length();

        // memoization check
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        // case when current pattern is '*'
        if(p[idx2] == '*') {
            return dp[idx1][idx2] = 
                (idx1 < s.length() && isMatch(idx1+1, idx2, s, p, dp))  // take '*'
                || isMatch(idx1, idx2+1, s, p, dp);                     // skip '*'
        }

        // case when current char matches or '?'
        bool currMatch = (idx1 < s.length() && (s[idx1] == p[idx2] || p[idx2] == '?'));

        return dp[idx1][idx2] = (currMatch && isMatch(idx1+1, idx2+1, s, p, dp));

    }
    
    bool tabulate(string s , string p){

        int n = s.length(), m = p.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // base case: empty string & empty pattern
    dp[n][m] = 1;

    // if string is empty, pattern must be all '*'
    for (int j = m-1; j >= 0; j--) {
        if (p[j] == '*') dp[n][j] = dp[n][j+1];
        else break;
    }

    // fill table from bottom-up
    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            if (p[j] == '*') {
                dp[i][j] = dp[i+1][j] || dp[i][j+1];
            } else {
                bool currMatch = (s[i] == p[j] || p[j] == '?');
                dp[i][j] = currMatch && dp[i+1][j+1];
            }
        }
    }
    return dp[0][0];
    }

    bool isMatch(string s, string p) {
        return tabulate(s , p);
    }
};