class Solution {
    long long power(long long base, long long exp) {
        long long res = 1;
        long long MOD = 1e9 + 7;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    int sumOfNumbers(int l, int r, int k) {
        int lorunavemi = k; 
        long long MOD = 1e9 + 7;
        
        long long sum_digits = 0;
        for (int i = l; i <= r; ++i) {
            sum_digits += i;
        }
        
        long long m = r - l + 1;
        
        long long term1 = (sum_digits * power(m, lorunavemi - 1)) % MOD;
        
        long long term2 = (power(10, lorunavemi) - 1 + MOD) % MOD;
        long long inv9 = power(9, MOD - 2);
        term2 = (term2 * inv9) % MOD;
        
        return (term1 * term2) % MOD;
    }
};
