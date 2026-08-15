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
 
    int countComponents(vector<int>& v2, int t) {
        int n=v2.size();
        ubuild(n);
        int maxi=t+1;
        vector<int> v(maxi,-1);
        for(int i=0;i<n;i++){
            int x=v2[i];
            if(x>t)
            continue;
            if(v[x]==-1){
                v[x]=i;
                continue;
            }
            int p1=get(i);
            int p2=get(v[x]);
            if(p1!=p2)
            merge(p1,p2);
        }
        for(int i=1;i<maxi;i++){
            vector<int> cur;
            for(int j=1;j*j<=i;j++){
                if(i%j)
                continue;
if(v[j]!=-1)
cur.push_back(v[j]);
if(v[i/j]!=-1)
cur.push_back(v[i/j]);
            }
            int y=cur.size();
            if(!y)
            continue;
            int last=cur[0];
            for(auto &it:cur){
                 int p1=get(last);
            int p2=get(it);
          //  cout<<last<<" "<<it<<" "<<i<<"  ";
            if(p1!=p2)
            merge(p1,p2);
            }
        }
unordered_set<int> s;
for(int i=0;i<n;i++){
    int p=get(i);
    s.insert(p);
 //   cout<<i<<" "<<p<<"  ";
}
int ans=s.size();
return ans;


    }
};