class Solution {
public:
    int palindromePartition(string s, int k) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,INT_MAX));
        dp[0][0]=0;
        vector<vector<int>> v(n+1,vector<int>(n+1));
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                int l=i;
                int r=j;
                while(l<r){
                    if(s[l-1]!=s[r-1])
                    v[i][j]++;
                    l++;
                    r--;

                }
            }
        }
        
        for(int i=1;i<=n;i++){
for(int j=1;j<=k;j++){
    if(dp[i-1][j-1]==INT_MAX)
    continue;
 
    for(int z=i;z<=n;z++){
dp[z][j]=min(dp[z][j],dp[i-1][j-1]+v[i][z]);
//cout<<z<<" "<<j<<" "<<dp[z][j]<<"  ";
    }

}
        }
        return dp[n][k];
    }
};