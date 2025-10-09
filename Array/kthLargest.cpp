class Solution { 
public:

    int partition(int left , int right , vector<int>& nums){
        int i = left;
        int pivot = nums[right];
         
        //Placing larger element to left of pivot 
        for(int j = left ; j < right ; j++){
            if(nums[j] > pivot){
                swap(nums[i] , nums[j]);
                i++;
            }
        }
        swap(nums[i] , nums[right]);  //Placing pivot at its right idx
        return i;       //return idx of pivot element
    } 


    int quickSelect(int left , int right , vector<int> & nums , int k){
        int partIdx;
        if(left <= right) 
           partIdx = partition(left,right,nums);

        if (partIdx == k - 1) return nums[partIdx];
        else if (partIdx > k - 1)
            return quickSelect(left, partIdx - 1, nums, k);
        else
            return quickSelect(partIdx + 1, right, nums, k);
        return -1;
    }
  
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(0 , nums.size() - 1 , nums , k );
    }
};