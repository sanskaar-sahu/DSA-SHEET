#include<bits/stdc++.h>

using namespace std;


//Problem link : https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532?leftPanelTabValue=PROBLEM

//MEMOIZATION CODE 


int ways(int idx, vector<int>& arr, int k, vector<vector<int>>& dp) {
    if (idx == 0) {
        if (k == 0) return 1;
        return arr[0] == k ? 1 : 0;
    }

    if (dp[idx][k] != -1) return dp[idx][k];

    int notpick = ways(idx - 1, arr, k, dp);
    int pick = 0;
    if (arr[idx] <= k)
        pick = ways(idx - 1, arr, k - arr[idx], dp);

    return dp[idx][k] = pick + notpick;
}

int tabulate(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    // Base case
    dp[0][0] = 1;  // One way to make sum 0 (pick nothing)
    if (arr[0] <= k) dp[0][arr[0]] = 1;  // One way to make sum arr[0] using only first element

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            int notpick = dp[i - 1][j];
            int pick = 0;
            if (arr[i] <= j)
                pick = dp[i - 1][j - arr[i]];

            dp[i][j] = pick + notpick;
        }
    }

    return dp[n - 1][k];
}

int findWays(vector<int>& arr, int k)
{
    int n = arr.size() ;;
	return tabulate(arr, k);

}
