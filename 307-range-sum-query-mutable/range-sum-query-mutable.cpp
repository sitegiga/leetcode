class NumArray {
    vector<int> bit, nums;
    int n;

    void updateBIT(int i, int diff) {
        for (; i <= n; i += i & -i)
            bit[i] += diff;
    }

    int queryBIT(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i)
            sum += bit[i];
        return sum;
    }

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        bit.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
            updateBIT(i + 1, nums[i]);
    }

    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        updateBIT(index + 1, diff);
    }

    int sumRange(int left, int right) {
        return queryBIT(right + 1) - queryBIT(left);
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */