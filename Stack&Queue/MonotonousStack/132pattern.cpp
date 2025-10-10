class Solution {
public:

    //Brute force
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++ ){
            for(int j = i+1 ; j < n ; j++){
                for(int k = j+1 ; k < n ; k++){
                      if(nums[j] > nums[k] && nums[j] > nums[i] && nums[i] < nums[k]){
                        return true;
                      }

                }
            }
        }
        return false;
    }
    
    bool find132pattern(vector<int>& nums) {
      int n = nums.size();
      int secL = INT_MIN;   //in the end second larget will be stored in it
      stack<int>st;    //in the end stack will be left with the largest element
      for(int i = n - 1; i >= 0 ; i -- ){
         if(nums[i] < secL) return true;
         
         while(!st.empty() && st.top() < nums[i]){
            secL = st.top();
            st.pop();
         }
         st.push(nums[i]);
      }
      return false;
    }
};