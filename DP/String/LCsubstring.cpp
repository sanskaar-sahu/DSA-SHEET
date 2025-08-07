//Problem Link : https://www.naukri.com/code360/problems/longest-common-substring_1214702?leftPanelTabValue=SUBMISSION

//tabula memoization TC = O(m*n) and SC =  O(m*n)

int LCSubStr(string &str1, string &str2){
    int len1 = str1.length();
    int len2 = str2.length();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    int ans = 0;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return ans;
}


//space optimization TC = O(len1 * len2) and SC = o(len2)
int LCSubStr(string &str1, string &str2){
    int len1 = str1.length();
    int len2 = str2.length();
    vector<int>prev(len1 + 1, 0);
    vector<int>curr(len2 + 1, 0);
    int ans = 0;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                curr[j] = 1 + prev[j - 1];
                ans = max(ans, curr[j]);
            } else {
                curr[j] = 0;
            }
        }
        prev = curr;
    }

    return ans;
}

