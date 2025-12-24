/*Given a string S consisting of the characters 0, 1 and 2.
Your task is to find the length of the smallest substring of string S
that contains all the three characters 0, 1 and 2.
If no such substring exists, then return -1.

Example 1:

Input:
S = 10212
Output:
3
Explanation:
The substring 102 is the smallest substring
that contains the characters 0, 1 and 2.
Example 2:

Input: 
S = 12121
Output:
-1
Explanation: 
As the character 0 is not present in the
string S, therefor no substring containing
all the three characters 0, 1 and 2
exists. Hence, the answer is -1 in this case.

*/

// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
       int n = S.length();
        int l = 0;
        int mini = INT_MAX;

        int zero = 0, ones = 0, two = 0;

        for (int i = 0; i < n; i++) {

            // Expand window
            if (S[i] == '0') zero++;
            if (S[i] == '1') ones++;
            if (S[i] == '2') two++;

            // Shrink window while valid
            while (zero > 0 && ones > 0 && two > 0) {
                mini = min(mini, i - l + 1);

                if (S[l] == '0') zero--;
                if (S[l] == '1') ones--;
                if (S[l] == '2') two--;
                l++;
            }
        }

        return (mini == INT_MAX) ? -1 : mini;
    }
};
