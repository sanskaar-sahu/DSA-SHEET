class Solution {
public:
    void nextPermutation(vector<int>& nums) {
            int n = nums.size();
        int idx = -1;

        // Step 1: find the breakpoint (first decreasing from right)
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        // Step 2: if no breakpoint, array is last permutation → reverse
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;  // important fix
        }

        // Step 3: find next greater element (rightmost > nums[idx])
        for (int i = n - 1; i > idx; i--) {
            if (nums[i] > nums[idx]) {
                swap(nums[idx], nums[i]);
                break;
            }
        }

        // Step 4: reverse suffix
        reverse(nums.begin() + idx + 1, nums.end());
    }
};