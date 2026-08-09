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
    vector<int> groupStrings(vector<string>& v) {
      unordered_map<int,int> mp;
        int n=v.size();
        ubuild(n);
        vector<int> v2(n);
        for(int i=0;i<n;i++){
            int cur=0;
            for(auto &itt:v[i]){
                int z=itt-'a';
                cur+=(1<<z);
            }
            if(mp.count(cur)){
                int p1=get(mp[cur]);
                int p2=get(i);
                if(p1!=p2)
                merge(p1,p2);
            }
            v2[i]=cur;
            mp[cur]=i;  
        }
        for(int i=0;i<n;i++){
            int cur=v2[i];
            for(int j=0;j<26;j++){
int z=(1<<j);
if(cur&z){
for(int k=0;k<26;k++){
    int a=(1<<k);
    if(cur&a)
    continue;
    int temp=cur-z+a;
     if(mp.count(temp)){
        int p1=get(mp[temp]);
        int p2=get(i);
        if(p1!=p2)
        merge(p1,p2);
    }
}
}
else{
    int temp=cur+z;
    if(mp.count(temp)){
        int p1=get(mp[temp]);
        int p2=get(i);
        if(p1!=p2)
        merge(p1,p2);
    }
}
            }

        }
        



        
unordered_set<int> s;
int x=0;
int y=0;
vector<int> ans;
for(int i=0;i<n;i++){
    int p=get(i);
if(s.count(p))
continue;
s.insert(p);
y++;
x=max(x,Size[p]);
}
ans.push_back(y);
ans.push_back(x);
return ans;
    }
};