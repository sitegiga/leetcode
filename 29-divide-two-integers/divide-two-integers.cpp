class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX; // overflow case

        long a = labs(dividend);
        long b = labs(divisor);
        long result = 0;

        while (a >= b) {
            long temp = b, multiple = 1;

            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            result += multiple;
        }

        // Apply sign
        if ((dividend < 0) ^ (divisor < 0))
            result = -result;

        return result;
    }
};
