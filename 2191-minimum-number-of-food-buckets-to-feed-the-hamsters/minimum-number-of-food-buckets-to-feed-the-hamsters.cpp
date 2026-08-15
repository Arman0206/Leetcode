class Solution {
public:
vector<int> v;
vector<vector<int>> dp;
int n;
int fun(int ind,int check){
if(ind==n){
    if(check)
    return 0;
    return n+2;
}
if(dp[ind][check]!=-1)
return dp[ind][check];
if(!check && v[ind])
return dp[ind][check]=n+2;
int ans=n+2;
if(!v[ind]){
ans=min(ans,1+fun(ind+1,2));
if(check)
ans=min(ans,fun(ind+1,1));
}
else if(check){
ans=min(ans,fun(ind+1,check-1));
}
//cout<<ind<<" "<<check<<" "<<ans<<"  ";
return dp[ind][check]=ans;
}
    int minimumBuckets(string s) {
        //0 left side need it 
        //1 nothing from left side
        //2 already filled
        for(auto &it:s){
if(it=='H')
v.push_back(1);
else
v.push_back(0);
        }
 n =v.size();
dp.assign(n,vector<int>(3,-1));
int x= fun(0,1);
if(x>n)
return -1;
return x;
    }
};