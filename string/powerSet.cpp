class Solution {

    void powerSet(vector<int>& nums , int idx , int n , vector<int>& subset, vector<vector<int>>& res){
         if(idx == n){
            res.push_back(subset);
            return;
         }

         //take el to a subset;
         subset.push_back(nums[idx]);
         powerSet(nums , idx+1 , n ,subset , res);
         subset.pop_back();

         //not take condition 
         powerSet(nums , idx + 1 , n , subset , res);
    }
      
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        int n = nums.size();

        powerSet(nums, 0,n, subset, res);
        return res;
    }
};