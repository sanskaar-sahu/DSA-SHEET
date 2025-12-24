/*
2461. Maximum Sum of Distinct Subarrays With Length K
You are given an integer array nums and an integer k.
 Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
    The length of the subarray is k, and
    All the elements of the subarray are distinct.
    Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,5,4,2,9,9,9], k = 3  sub = {4,2,9}
Output: 15



*/


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
            long long sum = 0, maxi = 0;
        int l = 0;
        unordered_set<int> st;

        for (int i = 0; i < nums.size(); i++) {

            // Remove duplicates
            while (st.find(nums[i]) != st.end()) {
                sum -= nums[l];
                st.erase(nums[l]);
                l++;
            }

            // Add current element
            sum += nums[i];
            st.insert(nums[i]);

            // If window size == k
            if (i - l + 1 == k) {
                maxi = max(maxi, sum);

                // Slide window
                sum -= nums[l];
                st.erase(nums[l]);
                l++;
            }
        }
        return maxi;
    }
};