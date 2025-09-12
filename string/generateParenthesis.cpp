class Solution {
public:
    void solve(int open , int close , int n , string& s , vector<string>& res ){
        if(open == n && close == n){
            res.push_back(s);
            return;
        }

        if(open < n){                 // we can still add '('
            s.push_back('(');
            solve(open + 1, close, n, s, res);
            s.pop_back();
        }

        if(close < open){              // only add ')' if valid
            s.push_back(')');
            solve(open, close + 1, n, s, res);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) { 
        vector<string>res;
        string s;
        int cnt = 0;
        solve(0 , 0 ,n, s , res);
        return res;
    }
};