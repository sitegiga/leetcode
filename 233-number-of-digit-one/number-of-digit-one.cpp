class Solution {
public:
    int countDigitOne(int n) {
        long long count = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long div = i * 10;
            count += (n / div) * i + min(max(n % div - i + 1, 0LL), i);
        }
        return count;
    }
};
