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
    int numberOfGoodPaths(vector<int>& val, vector<vector<int>>& edges) {
        int n=val.size();
        vector<vector<int>> v(1e5+1);
        for(int i=0;i<n;i++)
        v[val[i]].push_back(i);
        ubuild(n);
        vector<vector<int>> adj(n);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
               adj[it[1]].push_back(it[0]);
        }
        int ans=0;
for(auto &itt:v){
    unordered_map<int,int> mp;
    for(auto &it:itt){
        for(auto &e:adj[it]){
            if(val[e]>val[it])
            continue;
int p1=get(it);
int p2=get(e);
if(p1!=p2)
merge(p1,p2);
        }
    }
    for(auto &it:itt){
int p=get(it);
mp[p]++;
//cout<<it<<" "<<p<<"  ";
    }
    for(auto &it:mp){
        ans+=((it.second*(it.second-1))/2);
    }

}
return ans+n;

    }
};