class Solution {
public:
    int minPenalty(int t, vector<int>& lights, vector<int>& v) {
    int maxi=0;
    for(auto &it:lights)
    maxi=max(maxi,it);
    int ans=0;
    for(auto &it:v){
        int x=it%t;
        if(x==0)
        continue;
        if(x>=maxi)
        ans=max(ans,t-x);
    }
    return ans;
    }
};