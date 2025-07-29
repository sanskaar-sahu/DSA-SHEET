
//Leetcode 1143


class Solution{
 
    int LCSrecurr(int idx1 , int idx2 , string text1 , string text2){
        if(idx1 < 0 || idx2 < 0) return 0;

        if(text1[idx1] == text2[idx2]){
            return 1 + LCS(idx1 -1 , idx2 - 1 , text1 , text2);
        }
        return max(LCS(idx1-1 , idx2 , text1 , text2),LCS(idx1 ,idx2 - 1,text1 ,text2)); 
    }
     
    //memoization cpp

    int LCSmemo(int idx1 , int idx2 , string text1 , string text2 , vector<vector<int>>&dp){
        if(idx1 < 0 || idx2 < 0) return 0;


        if(dp[idx1][idx2]!= -1) return dp[idx1][idx2];

        if(text1[idx1] == text2[idx2]){
            return dp[idx1][idx2] = 1 + LCSmemo(idx1 -1 , idx2 - 1 , text1 , text2 , dp);
        }
        return  dp[idx1][idx2]  = max(LCSmemo(idx1-1 , idx2 , text1 , text2 , dp),LCSmemo(idx1 ,idx2 - 1,text1 ,text2 , dp)); 
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();

        // Always make text2 the shorter string to minimize space usage
        if (m > n) {
            swap(text1, text2);
            swap(n, m);
        }

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr; // Move current row to previous for next iteration
        }

        return prev[m];
    }




};