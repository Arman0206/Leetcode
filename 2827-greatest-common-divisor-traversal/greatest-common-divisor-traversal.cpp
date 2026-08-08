class Solution {
public:

vector<int> spf;
 int MAXN;
void sieve2()
{
    // stores smallest prime factor for every number
 
    spf[0] = 0;
    for (int i = 2; i <MAXN; i++) {
        if (spf[i] == 1) { // if the number is prime ,mark
                           // all its multiples who havent
                           // gotten their spf yet
            for (int j = i; j <MAXN; j += i) {
                if (spf[j]== 1){
                    spf[j] = i;
                }
            }
        }
    }
}
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
unordered_set<int> getFactorization(int x)
{
 unordered_set<int> ret;
    while (x != 1) {
        ret.insert(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
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
 
  
 
 
    bool canTraverseAllPairs(vector<int>& v) {
        int n=v.size();
        MAXN=100001;
        spf.assign(MAXN,1);
        vector<vector<int>> adj(100000+1);
        sieve2();
        for(int i=0;i<n;i++){
            unordered_set<int> s= getFactorization(v[i]);
            for(auto &itt:s)
            adj[itt].push_back(i);
        }
        ubuild(n);
        for(int i=0;i<100001;i++){
int x=adj[i].size();
if(x<2)
continue;
for(int j=1;j<x;j++){
   
int p1=get(adj[i][j-1]);
int p2=get(adj[i][j]);
if(p1!=p2)
merge(p1,p2);

 
}
        }

int p=get(0);
p=Size[p];
if(p==n)
return true;
return false;

    }
};