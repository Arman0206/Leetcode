class Solution {
public:
 vector<int> visited;
  set<pair<int,int>> res;
    vector<int> level;

 vector<set<int>> adj;
 int c;
 int dfs(int node,int depth){
    visited[node]=1;
    level[node]=depth;
    int z=depth;
for(auto &it:adj[node]){

if(visited[it]==2)
continue;
if(visited[it]){
  z=min(z,level[it]);
  res.insert({node,it});
    continue;
}
int x=dfs(it,depth+1);
z=min(z,x);
if(x>depth)
continue;
res.insert({node,it});

}
visited[node]=2;
return z;
 }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& e) {
        int n=e.size();
          vector<int> ans;
      //  ubuild(n);
      c=0;
      visited.resize(n);
      level.resize(n);
      adj.resize(n);
     
        vector<int> par(n,-1);
        int ind=-1;
        int p1=-1;
        int p2=-1;
        vector<int> deg(n);
        for(auto &it:e){
            it[0]--;
            it[1]--;
            deg[it[0]]++;
            deg[it[1]]++;
            adj[it[0]].insert(it[1]);
            if(par[it[1]]!=-1){
p1=par[it[1]];
p2=it[0];
ind=it[1];
            }
              par[it[1]]=it[0];
        }
      
       if(ind!=-1 && p1!=-1 && p2!=-1){ 
        adj[p2].erase(ind);
       for(int i=0;i<n;i++){
        if(par[i]==-1){
     int k=   dfs(i,0);
        }
       }
       for(int i=0;i<n;i++){
        if(!visited[i]){
            ans.push_back(p1+1);
                ans.push_back(ind+1);
                return ans;
        }
       }

 
               


  ans.push_back(p2+1);
                ans.push_back(ind+1);
                return ans;
    
        }
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
          int t=  dfs(i,0);
            }
        }
        for(int i=n-1;i>=0;i--){
if(res.count({e[i][0],e[i][1]})){
    ans.push_back(e[i][0]+1);
    ans.push_back(e[i][1]+1);
    return ans;
}
        }
        
        return ans;
    }
};