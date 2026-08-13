class Solution {
public:
vector<vector<int>> adj;
vector<int> v;
vector<int> visited;
int ans;
int dfs(int node,int last){
vector<int> temp;
int x=v[node];
int maxi=0;

if(v[node]!=last)
maxi=1;
visited[node]=1;
for(auto &it:adj[node]){
if(visited[it])
continue;
int y=dfs(it,x);
//cout<<node<<" "<<it<<" "<<y<<"  ";
ans=max(ans,1+y);
temp.push_back(y);
}
//cout<<node<<" "<<maxi<<"  ";
sort(temp.begin(),temp.end());
reverse(temp.begin(),temp.end());
if(temp.size()>1){
    ans=max(ans,1+temp[0]+temp[1]);
}
if(!maxi)
return maxi;
int sz=temp.size();
if(!sz)
return maxi;
sort(temp.begin(),temp.end());
reverse(temp.begin(),temp.end());
return temp[0]+1;
}
    int longestPath(vector<int>& p, string s) {
       int n=p.size();
       ans=1;
       for(auto &it:s)
       v.push_back((it-'a'));
       adj.resize(n);
       visited.resize(n);
       for(int i=1;i<n;i++){
     //   cout<<p[i]<<" "<<i<<"  ";
adj[p[i]].push_back(i);
       }
     int k=  dfs(0,26);

return ans;
    }
};