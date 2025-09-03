class Soltuion {
    public : 
     void insertionSort(vector<int>& arr){
        int sz = arr.size();

        for(int i = 0 ; i < sz ; i++){
            int j = i ;  //find the correct position of that element in that subarray

            while(j > 0 && arr[j-1] > arr[j]){
                swap(arr[j-1] , arr[j]);
                j--;
            }
        }
     }
}

//Worst case time complexity - O(n^2);
//Average case time complexity - O(n^2)
//Best case time complexity  - O(n)  - As nested loop isnt executed since the element is already place at right post
