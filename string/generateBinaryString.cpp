class Solution {
public:
    void solve(int idx , int  n , string & s,  vector<string>& ans){
       if(idx == n){
        ans.push_back(s);
        return;
       }

       s.push_back('1');
       solve(idx + 1 , n , s , ans);
       s.pop_back();

       if(idx == 0 || s.back() == '1'){
        s.push_back('0');
        solve(idx + 1 , n , s ,ans);
        s.pop_back();
       }

    }
    vector<string> validStrings(int n) {
        vector<string>res;
        string s;
        solve(0 , n , s , res);
        return res;
    }
};