/*
Given string s consisting only a,b,c. return the number of substrings containing 
at least one occurrence of all these characters a, b, and c.

Example 1:
Input: abcabc
Output: 10
Explanation:
The required substrings  are "abc", "abca", "abcab", "abcabc",
"bca", "bcab", "bcabc", "cab", "cabc" and "abc".

Example 2:

Input: aaacb
Output: 3
*/



class Solution {
  public:
    int countSubstring(string s) {
        // Code here
        int cnt[3] = {0,0,0};
        int n = s.length();
        int left = 0; 
        int ans = 0;
        for(int right = 0 ; right < n; right++){
            cnt[s[right] - 'a']++;
            while(cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0){
                ans+= n - right;
                cnt[s[left] - 'a']--;
                left++;
            }
        }
        
        return ans;
        
    }
};