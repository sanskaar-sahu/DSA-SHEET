class Solution {
public:
    
//    int LCS(int i , int j , string &s1 , string &s2){
//       if(i < 0 || j < 0) return 0;

//      int match = 0;
//      if(s1[i] == s2[j]) match = 1 +  LCS(i -1 , j-1 , s1 , s2);

//      int notmatch = max(LCS(i -1 , j , s1 , s2),LCS(i, j -1 , s1 , s2));

//      return max(match, notmatch);
//    }

    int longestCommonSubsequence(string text1, string text2) {
    int l1 = text1.length();
    int l2 = text2.length();

    // +1 for easier base case handling
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[l1][l2];
    }
       

    int longestPalindromeSubseq(string s) {
       string s2 = s;
       reverse(s2.begin(), s2.end());  // Reverse the string

        return longestCommonSubsequence(s , s2);
    }
};