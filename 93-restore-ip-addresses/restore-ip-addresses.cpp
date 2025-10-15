class Solution {
public:
    vector<string> res;
    void backtrack(string s, int idx, int dots, string path){
        if(dots==4 && idx==s.size()){
            res.push_back(path.substr(0, path.size()-1));
            return;
        }
        if(dots>4) return;
        for(int len=1; len<=3 && idx+len<=s.size(); len++){
            string part=s.substr(idx, len);
            if((part[0]=='0' && part.size()>1) || stoi(part)>255) continue;
            backtrack(s, idx+len, dots+1, path+part+".");
        }
    }
    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0, "");
        return res;
    }
};
