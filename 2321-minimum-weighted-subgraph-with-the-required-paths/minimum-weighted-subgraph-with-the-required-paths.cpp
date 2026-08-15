class Solution {
public:
using ll=long long;
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<ll,ll>>> adj(n);
         vector<vector<pair<ll,ll>>> radj(n);
        for(auto &it:edges){
        adj[it[0]].push_back({it[1],it[2]});
           radj[it[1]].push_back({it[0],it[2]});
        }
  vector<vector<ll>> dist(n,vector<ll>(3,LLONG_MAX));
      vector<int> v={src1,src2,dest};
      for(int i=0;i<3;i++){
        if(i==2){
            adj.clear();
            adj.resize(n);
            for(auto &it:edges)
             adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        pq.push({0,v[i]});
        dist[v[i]][i]=0;
        while(!pq.empty()){
            ll cur=pq.top().first;
            ll node=pq.top().second;
            pq.pop();
            if(dist[node][i]!=cur)
            continue;
            for(auto &it:adj[node]){
ll next=it.first;
ll temp=cur+it.second;
if(temp<dist[next][i]){
    dist[next][i]=temp;
    pq.push({temp,next});
}
            }
        }
      }
      ll ans=LLONG_MAX;
      for(int i=0;i<n;i++){
        ll cur=0;
    int check=0;
    for(int j=0;j<3;j++){
        if(dist[i][j]==LLONG_MAX){
            check=1;
            break;
           
        }
         cur+=dist[i][j];
    }
    if(check)
    continue;
    ans=min(ans,cur);
      }
if(ans==LLONG_MAX)
return -1;
return ans;
    }
};