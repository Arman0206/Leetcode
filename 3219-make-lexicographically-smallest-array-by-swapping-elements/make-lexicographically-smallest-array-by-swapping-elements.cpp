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
    vector<int> lexicographicallySmallestArray(vector<int>& v, int l) {
        int n=v.size();
        ubuild(n);
        vector<multiset<int>> adj(n);
        vector<pair<int,int>> vp(n);
        for(int i=0;i<n;i++){
vp[i]={v[i],i};
        }
sort(vp.begin(),vp.end());
     int last=vp[0].first;
     int ind=vp[0].second;
for(int i=1;i<n;i++){
    int z=abs(vp[i].first-last);  
    if(z<=l){
    int p1=get(ind);
    int p2=get(vp[i].second);
    if(p1!=p2)
    merge(p1,p2);
    }
     last=vp[i].first;
     ind=vp[i].second;
}
for(int i=0;i<n;i++){
    int p=get(i);
    adj[p].insert(v[i]);
}
vector<int> ans(n);
for(int i=0;i<n;i++){
int p=get(i);
auto it=adj[p].begin();
if(it!=adj[p].end())
ans[i]=(*it);
if(it!=adj[p].end())
adj[p].erase(it);
}
return ans;
    }
};