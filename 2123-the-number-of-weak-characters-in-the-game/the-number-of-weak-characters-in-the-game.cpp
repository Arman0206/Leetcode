class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& v) {
        int maxi=1e5+1;
        vector<vector<int>> adj(maxi);
        for(auto &it:v)
        adj[it[0]].push_back(it[1]);
        int ans=0;
        int maxx=0;
        for(int i=maxi-1;i>=1;i--){
            int x=adj[i].size();
            if(!x)
            continue;
sort(adj[i].begin(),adj[i].end());
for(auto &it:adj[i]){
    if(it<maxx)
    ans++;
    maxx=max(maxx,it);

}
        }
return ans;
    }
};