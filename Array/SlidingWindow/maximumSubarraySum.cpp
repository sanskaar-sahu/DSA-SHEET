// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
          
        int sum = 0;
        int maxi = INT_MIN;
        int n = arr.size();
        
        int start = 0;
        int resStart = 0, resEnd = 0;

        for (int i = 0; i < n; i++) {
            
            if (sum == 0)
                start = i;

            sum += arr[i];

            if (sum > maxi) {
                maxi = sum;
                resStart = start;
                resEnd = i;
            }

            if (sum < 0)
                sum = 0;
        }

        // If all elements are negative
        if (maxi < 0)
            return {-1};

        // Extract subarray
        vector<int> res(arr.begin() + resStart, arr.begin() + resEnd + 1);
        return res;
        
    }
};