class Solution {
public:
    int longestConsecutive(vector<int>& nums){
        unordered_set<int> s(nums.begin(), nums.end());
        int best=0;
        for(int x: s){
            if(!s.count(x-1)){
                int cur=x+1;
                while(s.count(cur)) cur++;
                best = max(best, cur - x);
            }
        }
        return best;
    }
};
