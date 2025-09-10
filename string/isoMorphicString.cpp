class Solution {
public:
    bool isIsomorphic(string s, string t) {

                if(s.size() != t.size()) return false;

        unordered_map<char,char> mp1; // s -> t
        unordered_map<char,char> mp2; // t -> s

        for(int i = 0 ; i < s.length() ; i++){
            char a = s[i], b = t[i];

            if(mp1.find(a) != mp1.end() && mp1[a] != b) return false;
            if(mp2.find(b) != mp2.end() && mp2[b] != a) return false;

            mp1[a] = b;
            mp2[b] = a;
        }

        return true;
    }
};