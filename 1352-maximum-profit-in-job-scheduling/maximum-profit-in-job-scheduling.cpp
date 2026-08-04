class Solution {
public:
vector<int> x,y;
vector<int> dp;
int n;
int fun(int ind){
    if(ind>=n)
    return 0;
    if(dp[ind]!=-1)
    return dp[ind];
    int ans=fun(ind+1);
    ans=max(ans,x[ind]+fun(y[ind]));
    return dp[ind]=ans;
}
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        vector<pair<pair<int,int>,int>> v;

         n=p.size();
        x.resize(n);
        y.assign(n,n);
        dp.assign(n,-1);
        map<int,int> mp;
        for(int i=0;i<n;i++){
            v.push_back({{s[i],e[i]},p[i]});
        }
        sort(v.begin(),v.end());
        for(int i=n-1;i>=0;i--){
            int st=v[i].first.first;
            int en=v[i].first.second;
            int z=v[i].second;
            x[i]=z;
auto it=mp.lower_bound(en);
mp[st]=i;
if(it==mp.end())
continue;
y[i]=it->second;
        }
return fun(0);


    }
};