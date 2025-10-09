class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        long long sumSkill = accumulate(skill.begin(), skill.end(), 0LL);
        long long prevWizardDone = sumSkill * mana[0];
        for (int j = 1; j < mana.size(); ++j) {
            long long prevPotionDone = prevWizardDone;
            for (int i = n - 2; i >= 0; --i) {
                prevPotionDone -= 1LL * skill[i + 1] * mana[j - 1];
                prevWizardDone = max(prevPotionDone, prevWizardDone - 1LL * skill[i] * mana[j]);
            }
            prevWizardDone += sumSkill * mana[j];
        }
        return prevWizardDone;
    }
};






