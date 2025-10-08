class Solution {
public:
    int findPeakElement(vector<int>& nums) {
           int low = 0;
        int high = nums.size() - 1;
        int n = nums.size();

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid + 1]) {
                // Peak is on the left side (including mid)
                high = mid;
            } else {
                // Peak is on the right side
                low = mid + 1;
            }
        }

        return low; 
    }
};