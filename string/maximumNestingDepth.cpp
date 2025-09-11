class Solution {
public:
    int maxDepth(string s) {
       int maxi = 0;
       int cnt = 0;
       for(char ch : s){
        if(ch == '(' ){
             ++cnt ; 
             maxi = max(maxi , cnt);}
        else if(ch == ')') cnt--;
       } 
       return maxi;
    }
};