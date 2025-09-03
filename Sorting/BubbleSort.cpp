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
                if(arr[j] < arr[i]){
                    swap(arr[i] , arr[j]);
                }
            }
        }
        
    }
};