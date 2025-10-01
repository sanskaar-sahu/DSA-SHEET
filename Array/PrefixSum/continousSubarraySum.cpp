class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
  
   /*
    for the subarray to have sum to be multiple of k and the 
    length of them should be two 
    
    (sum[i] - sum[j])%k == 0 && i - j >= 2 return true; => sum[i]%k = sum[j]%k &&
     i-j >= 2
    else return false;
   */

          unordered_map<int,int>mpp;
          mpp[0] = -1;
          int sum = 0;
          for(int i = 0 ; i < nums.size();i++){
              sum+= nums[i];
              int mod = sum% k;

              if(mpp.find(mod)!= mpp.end()){
                 if((i - mpp[mod]) > 1 ) return true;
              }else{
                mpp[mod] = i;
              }
          }
          return false;
    }
};