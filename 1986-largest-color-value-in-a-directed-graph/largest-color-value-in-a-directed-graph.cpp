class Solution {
public:
vector<int> visited;
vector<vector<int>> adj;
vector<int> c;
vector<int> v;
string s;
int ans;
int res;
vector<vector<int>> dp;
void dfs(int node){
    visited[node]=1;
    c[v[node]]++;
    for(int i=0;i<26;i++){
       
        res=max(res,c[i]);
    }
    dp[node][v[node]]++;
    for(auto &it:adj[node]){
if(visited[it]==2){
    for(int i=0;i<26;i++){
        res=max(res,c[i]+dp[it][i]);
      
        int x=0;
        if(i==v[node])
        x++;
        dp[node][i]=max(dp[node][i],x+dp[it][i]);
    }
    continue;
}
if(visited[it]==1){
    
    ans=-1;
    return;
}
dfs(it);
 for(int i=0;i<26;i++){
    //    res=max(res,c[i]+dp[it]][i]);
        int x=0;
        if(i==v[node])
        x++;
        dp[node][i]=max(dp[node][i],x+dp[it][i]);
    }


    }
    c[v[node]]--;
    visited[node]=2;
}
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        s=colors;
        for(auto &it:s)
        v.push_back((it-'a'));
        int n=s.size();
        ans=0;
        adj.resize(n);
        dp.resize(n,vector<int>(26));
        c.resize(26);
        visited.resize(n);
        res=0;
        vector<int> deg(n);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            deg[it[1]]++;
        }
        for(int i=n-1;i>=0;i--){
            if(!visited[i])
            dfs(i);
        }
if(ans)
return ans;
return res;

    }
};