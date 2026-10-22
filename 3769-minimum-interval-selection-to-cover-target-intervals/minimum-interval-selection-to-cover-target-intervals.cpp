class Solution {
public:
    int minSelection(vector<vector<int>>& a, vector<vector<int>>& b) {
        sort(a.begin(),a.end());
           sort(b.begin(),b.end());
        int maxi=1;
        vector<int> v(1e5+1);
        vector<vector<int>> adj(1e5+1);
        for(auto &it:a)
            adj[it[0]].push_back(it[1]);

             for(auto &it:b){
int st=max(it[0],maxi);
maxi=max(maxi,it[1]+1);
for(int i=st;i<=it[1];i++){
v[i]=1;
if(i==it[0])
v[i]=2;
}
        }
        int ans=0;
        int maxi2=0;
        int cur=0;
        for(int i=1;i<maxi;i++){
            for(auto &it:adj[i-1]){
            maxi2=max(maxi2,it);
         //   cout<<it<<" ";
            }

if(!v[i])
continue;
if(i<=cur)
continue;
if(v[i]==2){
      for(auto &it:adj[i]){
            maxi2=max(maxi2,it);
}}
if(maxi2<i){
return -1;
}
//cout<<i<<" ";
ans++;
cur=maxi2;
        }
        return ans;
    
    }
};