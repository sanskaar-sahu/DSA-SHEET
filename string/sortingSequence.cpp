class Solution {
public:
    string sortSentence(string s) {
        vector<string> str(10); // support up to 9 words
        int n = s.size();
        int start = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                string word = s.substr(start, i - start);   // get word+digit
                int idx = word.back() - '0';                // last char is index
                word.pop_back();                            // remove digit
                str[idx] = word;
                start = i + 1;
            }
        }

        // last word (no trailing space)
        string word = s.substr(start);
        int idx = word.back() - '0';
        word.pop_back();
        str[idx] = word;

        // build result
        string res;
        for (int i = 1; i < str.size(); i++) {
            if (str[i].empty()) continue;
            if (!res.empty()) res += " ";
            res += str[i];
        }

        return res;
    }
};