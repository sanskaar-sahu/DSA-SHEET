class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char,char>mpp1;
        unordered_map<char,char>mpp2;

        for(int i = 0 ; i < s.length() ; i++){
          
           if(mpp1.find(s[i]) != mpp1.end() || mpp2.find(t[i]) != mpp2.end()){
              if(mpp1[s[i]] != t[i] ||  mpp2[t[i]]!= s[i]) return false;
           }

            mpp1[s[i]] = t[i];
            mpp2[t[i]] = s[i];
        }

        return true;
    }
};