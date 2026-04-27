class Solution {
    public static int MOD = 1000000007;
    public int countGoodNumbers(long n) {
       long evenPositions = (n + 1) / 2;
        long oddPositions = n / 2;

        // Calculate (5^evenPositions * 4^oddPositions) % MOD
        long firstPart = power(5, evenPositions);
        long secondPart = power(4, oddPositions);

        return (int) ((firstPart * secondPart) % MOD);
    }
    long power(long base, long exp) {
    if (exp == 0) return 1; // Base case: anything^0 = 1
    
    long half = power(base, exp / 2); // Divide and conquer
    
    if (exp % 2 == 0) {
        return (half * half) % MOD; // If even: (x^2)^(n/2)
    } else {
        return (base * half * half) % MOD; // If odd: x * (x^2)^((n-1)/2)
    }
}
}
