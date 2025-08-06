
/* {
 Problem link : https://www.naukri.com/code360/problems/print-longest-common-subsequence_8416383?leftPanelTabValue=SUBMISSION
} */


string longestCommonSubsequence(string text1, string text2) {
     int l1 = text1.length();
    int l2 = text2.length();

    // Initialize dp table with an extra row and column
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

    // Build the dp table
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Backtrack to find the LCS string
    int i = l1, j = l2;
    string ans = "";

    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            ans.push_back(text1[i - 1]);
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // LCS was built in reverse
    reverse(ans.begin(), ans.end());
    return ans;
    }


string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.	
	return longestCommonSubsequence(s1 , s2);
	
}