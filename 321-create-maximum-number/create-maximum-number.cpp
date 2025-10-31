class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> best;
        for (int i = max(0, k - (int)nums2.size()); i <= min(k, (int)nums1.size()); i++) {
            vector<int> cand = merge(maxSub(nums1, i), maxSub(nums2, k - i));
            best = max(best, cand);
        }
        return best;
    }

    vector<int> maxSub(vector<int>& nums, int k) {
        vector<int> res;
        int drop = nums.size() - k;
        for (int n : nums) {
            while (drop && res.size() && res.back() < n) {
                res.pop_back();
                drop--;
            }
            res.push_back(n);
        }
        res.resize(k);
        return res;
    }

    vector<int> merge(vector<int> a, vector<int> b) {
        vector<int> res;
        while (a.size() || b.size()) {
            if (a > b) res.push_back(a[0]), a.erase(a.begin());
            else res.push_back(b[0]), b.erase(b.begin());
        }
        return res;
    }
};
