class Solution {
public:
vector<vector<int>> dp;
string s1,s2;
int n,m;
string s;
int fun(int i,int j){
    if(i== n || j==m)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int ans=fun(i+1,j);
    ans=max(ans,fun(i,j+1));
    if(s1[i]==s2[j]){
        ans=max(ans,1+fun(i+1,j+1));
    }
    return dp[i][j]=ans;
}
void rec(int i,int j){
if(j==m && i==n)
return ;
//cout<<i<<" "<<j<<"  ";
if(i<n && j<m){
    if(s1[i]==s2[j]){
    s+=s1[i];
    rec(i+1,j+1);
    return;
    }
    if(dp[i+1][j]>=dp[i][j+1]){
 s+=s1[i];
    rec(i+1,j);
    return;
    }
    s+=s2[j];
    rec(i,j+1);
    return;
}
if(i<n){
    s+=s1[i];
    rec(i+1,j);
    return;
}
  s+=s2[j];
    rec(i,j+1);
    return;
}
    string shortestCommonSupersequence(string str1, string str2) {
        s1=str1;
        s2=str2;
        n=s1.size();
        m=s2.size();
        dp.resize(n+1,vector<int>(m+1,-1));
     int x=   fun(0,0);
        rec(0,0);
        return s;
    }
};