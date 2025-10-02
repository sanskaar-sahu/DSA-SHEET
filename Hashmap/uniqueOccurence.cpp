class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       vector<int>res(2001 , 0);
       for(int i = 0 ; i < arr.size();i++){
          int idx = arr[i] + 1000;
          res[idx]++;
       }

       sort(res.begin(),res.end());

       for(int i = 0 ; i < 2001 ; i++){
        if(res[i] == 0) continue;
        if( (i-1 > 0) &&  res[i-1] == res[i]) return false;
       }
       return true;
    }
};