class Solution {
public:
    int minDays(int n) {
    vector<int> dp(n+1,3*n);
    dp[0]=-1;
    for(int i=1;i<=n;i++){
        int cur=0;
        for(int j=1;j<=500;j++){
            cur+=j;
            if(cur>i)
            break;
            dp[i]=min(dp[i],dp[i-cur]+j+1);
        }
    }
    return dp[n];
    }
};