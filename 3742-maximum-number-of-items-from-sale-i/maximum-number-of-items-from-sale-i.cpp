class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& v, int b) {
vector<int> price;
int n=v.size();
vector<int> count(n,1);
for(int i=0;i<n;i++){
    price.push_back(v[i][1]);
    for(int j=0;j<n;j++){
        if(i==j)
        continue;
        if(!(v[j][0]%v[i][0]))
        count[i]++;
    }
}
vector<vector<int>> dp(n,vector<int>(b+1));
//dp[0][b]=0;
int ans=0;
if(b>=price[0])
dp[0][price[0]]=count[0];
for(int i=0;i<n;i++){
  // cout<< count[i]<<"  ";
for(int j=0;j<=b;j++){
    if(i)
dp[i][j]=dp[i-1][j];
if(j>=price[i]){
    if(i)
    dp[i][j]=max(dp[i][j],dp[i-1][j-price[i]]+count[i]);
   dp[i][j]=max(dp[i][j],dp[i][j-price[i]]+1);
    
}
//cout<<i<<" "<<j<<" "<<dp[i][j]<<"  ";
ans=max(ans,dp[i][j]);
}

}



       return ans;
      // return dp[n-1];
    }
};