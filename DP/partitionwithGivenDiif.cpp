#include <bits/stdc++.h> 


int count(int idx ,vector<int> &arr ,int target){
    if(idx == 0){
        if(target == 0){
            return 1;
        }
        if(arr[0]== target) return 1;
    }

    //pick 
    int pick = count(idx-1 , arr , target - arr[idx]);
    int not_pick = count(idx-1 , arr , target);

    return pick + not_pick;
    
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int sum = 0;
    for(auto it : arr) sum+= it;

    /*
     s1 - s2 = d && s1 >= s2
     (total - s2) - s2 = d;
     s2 = (total -d)/2
    */

    int s2 = (sum-d)/2;

    return count(n-1 ,arr , s2);


}


