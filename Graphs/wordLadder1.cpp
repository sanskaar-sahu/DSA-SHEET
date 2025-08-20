class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set<string> dict(wordList.begin(), wordList.end());
        if(dict.find(endWord) == dict.end()) return 0; // endWord must exist in dictionary

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        while(!q.empty()){
            auto [word, steps] = q.front();
            q.pop();

            if(word == endWord) return steps;

            for(int i = 0; i < word.size(); i++){
                char org = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    if(ch == org) continue;  // skip same letter
                    word[i] = ch;
                    if(dict.find(word) != dict.end()){
                        dict.erase(word);  // mark visited
                        q.push({word, steps + 1});
                    }
                }
                word[i] = org; // restore
            }
        }
        return 0;
    }
};