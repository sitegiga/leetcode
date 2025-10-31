class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (citations[m] >= n - m) r = m - 1;
            else l = m + 1;
        }
        return n - l;
    }
};
