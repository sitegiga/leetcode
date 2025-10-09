class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        unordered_map<string, int> wordMap;

        for (auto& w : words) wordMap[w]++;

        for (int i = 0; i < wordLen; ++i) {
            int left = i, count = 0;
            unordered_map<string, int> seen;

            for (int right = i; right + wordLen <= s.size(); right += wordLen) {
                string word = s.substr(right, wordLen);
                if (wordMap.count(word)) {
                    seen[word]++;
                    count++;

                    while (seen[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == wordCount)
                        result.push_back(left);
                } else {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        return result;
    }
};