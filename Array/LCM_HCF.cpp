#include <bits/stdc++.h>
using namespace std;

// Check if 'mini' is HCF of all elements
bool isHCF(vector<int>& arr, int mini, int n) {
    int idx = 0;
    while (idx < n) {
        if (arr[idx] % mini == 0)
            idx++;
        else
            break;
    }

    if (idx == n) return true;   // fixed from n-1 → n
    return false;
}

// Find HCF by testing divisors (your original idea, fixed)
int findHCF(vector<int>& arr, int mini, int n) {
    if (isHCF(arr, mini, n)) return mini;

    for (int i = 2; i <= mini; i++) {
        int fact = mini / i;
        if (fact == 0) continue;
        if (isHCF(arr, fact, n)) return fact;
    }

    return 1;
}

//  Check if 'maxi' is LCM of all elements
bool isLCM(vector<int>& arr, int maxi, int n) {
    int idx = 0;
    while (idx < n) {
        if (maxi % arr[idx] == 0)
            idx++;
        else
            break;
    }

    if (idx == n) return true;   // fixed from n-1 → n
    return false;
}

// Find LCM by testing multiples (your logic, fixed)
int findLCM(vector<int>& arr, int maxi, int n) {
    if (isLCM(arr, maxi, n)) return maxi;

    int idx = 2;
    long long mul = (long long)idx * maxi;

    while (true) {
        if (isLCM(arr, mul, n)) return mul;
        idx++;
        mul = (long long)idx * maxi;

        // safety check to avoid infinite loop
        if (mul > 1e9) break;
    }

    return -1; // if not found within limit
}

int main() {
    vector<int> arr = {2, 4, 8, 16};
    int n = arr.size();

    int mini = *min_element(arr.begin(), arr.end());
    int maxi = *max_element(arr.begin(), arr.end());

    cout << "LCM OF NUMBERS = " << findLCM(arr, maxi, n) << endl;
    cout << "HCF OF NUMBERS = " << findHCF(arr, mini, n) << endl;

    return 0;
}
