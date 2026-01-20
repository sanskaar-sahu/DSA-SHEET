/**
 Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
 */

class Solution {
public:
    int longestPalindrome(string s) {
      int cnt = 0 ;
      vector<int>lower(26,0);
      vector<int>upper(26,0);
      bool oddChar = false;

      for(int i = 0; i < s.length() ; i++){
         char ch = s[i];
         if(ch >= 'a' && ch<= 'z'){
            lower[ch - 'a']++;
         }else upper[ch - 'A']++
      }

      for(int i = 0 ; i < 26 ; i++){
         if(lower[i]%2 == 0){
            cnt+= lower[i];
         }else{
            cnt+= lower[i] -1;
            oddPresent = true;
         }
         
        if(upper[i]%2 == 0){
            cnt+= upper[i];
         }else{
            cnt+= upper[i] -1;
            oddPresent = true;
         }
      }

      if(oddPresent) cnt++;

      return cnt;
    }
};