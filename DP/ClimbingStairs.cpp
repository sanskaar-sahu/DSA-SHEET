#include<iostream>
#include<vector>
using namespace std;


int solve(int n , vector<int>& dp){
    
    if(n <= 2) return  dp[n] = n; //breaking condition 

    if(dp[n] != -1) return dp[n]; //memoization check

    return dp[n] = solve(n - 1 , dp) + solve(n-2 ,  dp); // dp calculation

}

int main(){
    int n ;
    cout<<"Enter number of stairs ";
    cin>> n;
    //making it as dynamic programming 
    //Step 1 initialise dp array 
    vector<int>dp(n+1 , -1);

    //add inital breaking condition 
    int count  = solve( n  , dp);
    
    cout << "Total ways: " << count << endl;

    return 0;
}