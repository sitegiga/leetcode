class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int n = nums.size(), j = (n + 1) / 2 - 1, k = n - 1;
        for (int i = 0; i < n; i++)
            nums[i] = i % 2 == 0 ? sorted[j--] : sorted[k--];
    }
};
