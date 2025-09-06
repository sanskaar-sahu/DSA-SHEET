
//Que = https://www.geeksforgeeks.org/problems/ncr1019/1

class Solution {
  public:
    int nCr(int n, int r) {
        if (r > n) return 0;
        if (r == 0 || n == r) return 1;
        
        if (r > n - r) r = n - r;  // use symmetry property
        
        long long res = 1;  // to avoid overflow
        for (int i = 0; i < r; i++) {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return (int)res;
    }
};