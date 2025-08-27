// User function Template for C++
#include<bits/stdc++.h>
class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int sum = 0;
        int temp = n;
        while(n > 0){
            int dig = n % 10;
            sum+= pow(dig , 3);
            n/=10;
        }
        
        return (sum == temp);
        
        
    }
};