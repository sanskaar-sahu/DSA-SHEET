class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>words;
        stringstream ss(s);
        string word;
        while(ss >> word){
            words.push_back(word);
        }

        if(words.size() != pattern.size()) return false;

        unordered_map<char,string> mpp1; //char--->string
        unordered_map<string,char>mpp2;  //string ---> word

        for(int i = 0 ; i < words.size() ; i++){
            string word = words[i];
            char p = pattern[i];
            
            if(mpp1.count(p) && mpp1[p] != word) return false;
            if(mpp2.count(word) && mpp2[word] != p) return false;

            mpp1[p] = word;
            mpp2[word] = p;

         }
         return true;
    }
};