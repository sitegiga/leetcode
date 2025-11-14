class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Count frequency of each element
        for(int n : nums) {
            freq[n]++;
        }

        // Max heap: pair<frequency, number>
        priority_queue<pair<int,int>> maxHeap;

        for(auto &p : freq) {
            maxHeap.push({p.second, p.first});
        }

        // Extract top k frequent elements
        vector<int> result;
        while(k--) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};
