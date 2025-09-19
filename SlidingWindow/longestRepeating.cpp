class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mpp(26, 0);
        int l = 0, maxLen = 0, mfreq = 0;

        for (int r = 0; r < s.length(); r++) {
            mpp[s[r] - 'A']++;
            mfreq = max(mfreq, mpp[s[r] - 'A']);

            while ((r - l + 1) - mfreq > k) {
                mpp[s[l] - 'A']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};