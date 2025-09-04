class Solution {
    void swap(int &a , int &b){
        int temp = a;
        a = b;
        b = temp;
    }
  public:
    void bubbleSort(vector<int>& arr) {
        // code here
        int sz = arr.size();
        
        for(int i = 0 ; i < sz ; i++){
            for(int j = i+1 ; j < sz ; j++){
                if(arr[j] >= arr[j+1]){
                    swap(arr[i] , arr[j]);
                }
            }
        }
        
    }

void recurBubbleSort(vector<int>& arr, int n, int i, int j) {
    // Base case: if all passes are done
    if (i == n - 1) return;

    // If we reached end of this pass, start next pass
    if (j == n - i - 1) {
        recurBubbleSort(arr, n, i + 1, 0);
        return;
    }

    // Compare and swap
    if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
    }

    // Move to next j in this pass
    recurBubbleSort(arr, n, i, j + 1);
}
};