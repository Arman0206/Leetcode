class Solution {
public:
vector<int> dp;
string s;
int n;
int fun(int ind){
    if(ind==n)
    return 0;
    if(dp[ind]!=-1)
    return dp[ind];
    long long  md=1e9+7;
    long long mul=1;
    long long x=0;
   long long y=0;
   long long  hash=1;
   int ans=3000;
    for(int i=ind;i<n;i++){
int k=s[i]-'a';
x=(x*31)%md;
x=(x+k)%md;
long long  z=(hash*k)%md;
y=(y+z)%md;
hash=(hash*31)%md;
if(x==y){
   // cout<<ind<<" "<<i+1<<"  ";
ans=min(ans,1+fun(i+1));
}
    }
return dp[ind]=ans;
}
    int minCut(string s2) {
        s=s2;
        n=s.size();
        dp.assign(n,-1);
        return fun(0)-1;
    }
};