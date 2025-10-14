class Solution {
private:
    // Helper function using long long for the exponent
    double power(double x, long long N) {
        if (N == 0) return 1.0;
        
        // Handle negative exponent by converting to positive
        if (N < 0) {
            return 1.0 / power(x, -N);
        }

        double half = power(x, N / 2);
        
        // Check if N is even or odd
        if (N % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }

public:
    double myPow(double x, int n) {
        // Cast n to long long to safely handle the minimum int value
        return power(x, (long long)n);
    }
};

