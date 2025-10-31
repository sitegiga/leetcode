class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = nums.size() * (nums.size() + 1) / 2;
        for (int n : nums) sum -= n;
        return sum;
    }
};
