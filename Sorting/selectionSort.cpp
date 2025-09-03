class Solution {
  void swap(int &a , int &b){
      int temp =a;
      a = b;
      b = temp;
  }
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // code here
        int n = arr.size();
        for(int i = 0 ; i < n ; i++){
            int minIdx = i;
            for(int j = i+1 ; j < n ; j++){
                if(arr[j] < arr[minIdx]){
                    minIdx = j;
                }
            }
            swap(arr[i] , arr[minIdx]);
        }
    }
};
// Time Complexity : O(n^2) 
// Best case time complexity : O(n^2)
// Worst case time complexity : O(n^2)
// Auxiliary Space : O(1)