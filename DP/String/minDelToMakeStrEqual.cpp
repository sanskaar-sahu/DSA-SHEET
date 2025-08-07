class Solution {
public:
    
int longestCommonPalindrome(string s1 , string s2){
    int l1 = s1.length();
    int l2= s2.length();
    vector<vector<int>> dp(l1, vector<int>(l2, 0));

    // Fill first cell
    if (s1[0] == s2[0])
        dp[0][0] = 1;

    // Fill first row
    for (int j = 1; j < l2; j++) {
        if (s1[0] == s2[j])
            dp[0][j] = 1;
        else
            dp[0][j] = dp[0][j-1];
    }

    // Fill first column
    for (int i = 1; i < l1; i++) {
        if (s1[i] == s2[0])
            dp[i][0] = 1;
        else
            dp[i][0] = dp[i-1][0];
    }

    // Fill the rest of the table
    for (int i = 1; i < l1; i++) {
        for (int j = 1; j < l2; j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[l1 - 1][l2 - 1];
}

    int minDistance(string word1, string word2) {
       int common = longestCommonPalindrome(word1 , word2);
       return (word1.length() - common) +( word2.length() - common);
    }
};