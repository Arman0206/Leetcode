class Solution {
public:
	vector<int> parent;
    vector<int> Size;
    void ubuild(int n){
        parent.resize(n);
        for(int i=0;i<n;i++)
        parent[i]=i;
        Size.assign(n,1);
        
    }
int get(int a) {
		return parent[a] = (parent[a] == a ? a : get(parent[a]));
	}
  void merge(int i, int j) {
      
        // Find the representatives (or the root nodes) for
        // the set that includes i
        int irep = get(i);

        // And do the same for the set that includes j
        int jrep = get(j);

        // Elements are in the same set, no need to unite
        // anything.
        if (irep == jrep)
            return;

        // Get the size of i’s tree
        int isize = Size[irep];

        // Get the size of j’s tree
        int jsize = Size[jrep];

        // If i’s size is less than j’s size
        if (isize < jsize) {
          
            // Then move i under j
            parent[irep] = jrep;

            // Increment j's size by i's size
            Size[jrep] += Size[irep];
        }
        // Else if j’s size is less than i’s size
        else {
            // Then move j under i
            parent[jrep] = irep;

            // Increment i's size by j's size
            Size[irep] += Size[jrep];
        }}
    vector<int> findAllPeople(int n, vector<vector<int>>& m, int f) {
        int maxi=1e5;
        maxi++;
        vector<vector<pair<int,int>>> v(maxi);
        vector<vector<int>> adj(n);
        ubuild(n);
        merge(0,f);
        for(auto &it:m){
            v[it[2]].push_back({it[0],it[1]});
        }
      for(int i=0;i<maxi;i++){
        int z=v[i].size();
        if(!z)
        continue;
unordered_set<int> s;
unordered_set<int> visited;
for(auto &it:v[i]){
s.insert(it.first);
s.insert(it.second);
adj[it.first].push_back(it.second);
adj[it.second].push_back(it.first);
}
queue<int> q;
for(auto &it:s){
    int p1=get(0);
    int p2=get(it);
 
    if(p1==p2){
    q.push(it);
    visited.insert(it);
    }
}
while(!q.empty()){
    int node=q.front();
    visited.insert(node);
    q.pop();
    for(auto &it:adj[node]){
       //  cout<<it<<" ";
        if(visited.count(it))
        continue;
        int p1=get(0);
        int p2=get(it);
    visited.insert(it);
       
        if(p1!=p2)
        merge(p1,p2);
        q.push(it);
    }
}




for(auto &it:s)
adj[it].clear();
      }
int p=get(0);
vector<int> ans;
for(int i=0;i<n;i++){
    int x=get(i);
    if(x==p)
    ans.push_back(i);
}
return ans;
    }
};