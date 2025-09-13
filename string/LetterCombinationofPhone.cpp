class Solution {
    void result(int idx, int n , string& str , unordered_map<int , string >& mpp, vector<string>& res , string digits){

        if(idx >= n){
            res.push_back(str);
            return;
        }

        for(int i = 0 ; i < mpp[digits[idx] - '0'].size() ; i++){
           str.push_back(mpp[digits[idx] - '0'][i]);  //picked the digit
           result(idx + 1 , n , str , mpp , res , digits);
           str.pop_back();
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
       vector<string>res;
       if(digits.length() == 0) return res;

       unordered_map<int , string >mpp;
       mpp[2] = "abc";
       mpp[3] = "def";
       mpp[4] = "ghi";
       mpp[5] = "jkl";
       mpp[6] = "mno" ;
       mpp[7] = "pqrs";
       mpp[8] = "tuv" ; 
       mpp[9] = "wxyz";

        if (digits.length() == 1) {
            for (char c : mpp[digits[0] - '0']) {
                res.push_back(string(1, c));  // ✅ wrap char into string
            }
            return res;
        }

       int n = digits.size();
       string str;
       result(0 , n , str , mpp ,  res, digits);
       return res;
     }
};