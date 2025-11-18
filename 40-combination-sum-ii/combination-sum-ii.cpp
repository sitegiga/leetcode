class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, int target, int start, vector<int>& path) {
        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates
            if (i > start && nums[i] == nums[i - 1]) continue;

            if (nums[i] > target) break; // No need to continue

            path.push_back(nums[i]);
            backtrack(nums, target - nums[i], i + 1, path);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        backtrack(candidates, target, 0, path);
        return result;
    }
};
