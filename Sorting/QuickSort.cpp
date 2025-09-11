class Solution {
    public:
    
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low];  // choosing first element as pivot
        int i = low, j = high;

        while (i < j) {
            while (i <= high && arr[i] <= pivot) i++;
            while (j >= low && arr[j] > pivot) j--;
            if (i < j) swap(arr[i], arr[j]);
        }
        swap(arr[low], arr[j]);
        return j;
    }

      void quickSort(vector<int>& arr , int low , int high){
        if(low < high){
            int partIdx = partition(arr , low , high);
            quickSort(arr , low , partIdx)
            quickSort(arr , partIdx + 1 , high);
        }
      } 
     
}