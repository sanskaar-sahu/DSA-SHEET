class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        if(n <= 0) return;     // handle invalid input
        
        cout << 1 << " ";      // 1 always divides n
        
        for(int div = 2; div <= n/2; div++){
            if(n % div == 0) cout << div << " ";
        }
        
        if(n != 1) cout << n;  // n itself is always a divisor (except when n=1)
    }
};