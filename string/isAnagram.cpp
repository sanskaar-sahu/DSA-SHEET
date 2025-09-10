class Solution {
public:
    bool isAnagram(string s, string t) {
            if (s.size() != t.size()) return false;  // early check

        int freq[26] = {0};

        for (char ch : s) {
            freq[ch - 'a']++;   // count letters in s
        }

        for (char ch : t) {
            freq[ch - 'a']--;   // remove counts for t
            if (freq[ch - 'a'] < 0) return false; // extra safety
        }

        // No need to check again, because sizes are equal
        return true;
    }
};