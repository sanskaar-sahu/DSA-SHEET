    
    int findKthRotation(vector<int> & arr){

    int n = arr.size();
        int low = 0, high = n - 1;
        int ans = INT_MAX;
        int index = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If left half is sorted
            if (arr[low] <= arr[mid]) {
                // update minimum if needed
                if (arr[low] < ans) {
                    ans = arr[low];
                    index = low;
                }
                // move to right half
                low = mid + 1;
            } 
            // Right half is sorted
            else {
                if (arr[mid] < ans) {
                    ans = arr[mid];
                    index = mid;
                }
                high = mid - 1;
            }
        }

        return index; // rotation count
}