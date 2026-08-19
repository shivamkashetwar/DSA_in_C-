class Solution {
public:
    int countPrimes(int n) {
        // Base case: there are no primes less than 2
        if (n <= 2) return 0;
        
        // Initialize the boolean vector with the name 'isprime'
        vector<bool> isprime(n, true);
        int count = 0;

        for (int i = 2; i < n; i++) {
            if (isprime[i]) {
                count++;
                
                // Mark all multiples of the current prime as non-prime
                // Note: j increments by i, not 1
                for (long long j = (long long)i * i; j < n; j += i) {
                    isprime[j] = false;
                }
            }
        }
        
        return count;
    }
};