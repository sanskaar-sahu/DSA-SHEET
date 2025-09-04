class Solution {
public:
    string reverseWords(string s) {
        // Step 1: reverse the whole string
        reverse(s.begin(), s.end());
        int n = s.length();

        string res;
        int i = 0;

        while (i < n) {
            // skip spaces
            while (i < n && s[i] == ' ') i++;

            if (i >= n) break;

            // extract one word
            string word;
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // reverse the word
            reverse(word.begin(), word.end());

            // add to result
            if (!res.empty()) res += " "; // add space between words
            res += word;
        }

        return res;
    }
};