class Solution {
  public:
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> res;
        int left = low;
        int right = mid + 1;

        // merge two sorted halves
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                res.push_back(arr[left]);
                left++;
            } else {
                res.push_back(arr[right]);
                right++;
            }
        }

        // remaining left half
        while (left <= mid) {
            res.push_back(arr[left]);
            left++;
        }

        // remaining right half
        while (right <= high) {
            res.push_back(arr[right]);
            right++;
        }

        // copy back into original array
        for (int i = low; i <= high; i++) {
            arr[i] = res[i - low];
        }
    }

    void mS(vector<int>& arr, int l, int r) {
        if (l >= r) return;
        
        int mid = l + (r - l) / 2;
        
        mS(arr, l, mid);
        mS(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        mS(arr,l,r);
    }
};


//Time complexity is O(n*log n)

//Space complexity is O(n)