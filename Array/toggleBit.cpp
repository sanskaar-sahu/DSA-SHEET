#include <bits/stdc++.h>
using namespace std;

string toggleBits(int n) {
    string res = "";
    while (n > 0) {
        int rem = n % 2;
        res += to_string(rem);
        n /= 2;
    }
    reverse(res.begin(), res.end());

    // toggle bits
    for (int i = 0; i < res.length(); i++) {
        res[i] = (res[i] == '1') ? '0' : '1';
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    string binary = toggleBits(n);
    int result = 0;
    int power = 0;

    // convert toggled binary to decimal
    for (int i = binary.length() - 1; i >= 0; i--) {
        int num = binary[i] - '0';
        result += num * (1 << power);
        power++;
    }

    cout << result << endl;
    return 0;
}
