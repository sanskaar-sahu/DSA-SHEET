class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         //element are sorted on the basis of alphabetical order regardless of size
        sort(strs.begin() , strs.end()); 
        int n = strs.size();
        string first = strs[0];
        string last = strs[n-1];
        string rs;

        for(int i = 0 ; i < first.length() ; i++){
            if(i < last.length() && first[i] == last[i]){
                rs+= first[i];
            }else{v
                break;   //break at first mismatch
            }
        }

        return rs;
    }
};