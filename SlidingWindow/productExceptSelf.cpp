class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {


        int sz = nums.size();

        if(sz <= 1) return nums; 


        vector<int>suff(sz);
        suff[sz - 1] = nums[sz - 1];

        for(int i = nums.size() -2 ; i>= 0 ; i--){
            suff[i] = suff[i+1] *nums[i];
        }

        vector<int>prefix(sz);
        prefix[0] = nums[0];
        for(int i = 1; i < sz ;i++){
            prefix[i] = prefix[i-1]*nums[i];
        }

        vector<int>res(sz);
        res[0] = suff[1];
        res[sz-1] = prefix[sz - 2];

        for(int i = 1 ; i < sz -1 ; i++){
            res[i] = prefix[i-1] * suff[i+1];
        }

        return res;   
    }
};