class Solution {
public:
    int longestCommonPalindrome(string s1 , string s2){
        int l1 = s1.length();
        vector<vector<int>>dp(l1+1 ,vector<int>(l1+1 , 0));

        for(int i = 1; i <=l1 ; i++){
           for(int j = 1 ; j<=l1 ;j++){
              if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
              }else{
                 dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
              }
           }
        }
        return dp[l1][l1]; //since l1 = l2
    }
    int minInsertions(string s) {
        string s2 = s;
        reverse(s2.begin() , s2.end());
        return (s.length() -  longestCommonPalindrome(s ,s2));
    }
};