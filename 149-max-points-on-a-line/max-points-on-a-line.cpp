class Solution {
public:
    int maxPoints(vector<vector<int>>& p){
        int n=p.size(), res=0;
        if(n<3) return n;
        for(int i=0;i<n;i++){
            unordered_map<double,int> slope;
            int dup=1;
            for(int j=i+1;j<n;j++){
                if(p[i]==p[j]){ dup++; continue; }
                double m = p[i][0]==p[j][0] ? DBL_MAX :
                            (double)(p[j][1]-p[i][1])/(p[j][0]-p[i][0]);
                slope[m]++;
            }
            res=max(res, dup);
            for(auto &x:slope) res=max(res, x.second+dup);
        }
        return res;
    }
};
