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
 
    vector<int> hitBricks(vector<vector<int>>& v, vector<vector<int>>& q) {
        int n=v.size();
        int m=v[0].size();
        int t=q.size();
        vector<int> ans(t);
        int sz=0;
         reverse(q.begin(),q.end());
        for(auto &it:q){
            if(v[it[0]][it[1]])
            ans[sz]=1;
        v[it[0]][it[1]]=0;
        sz++;
        }
       ubuild(n*m);
       vector<int> dx={1,-1,0,0};
       vector<int> dy={0,0,1,-1};
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!v[i][j])
            continue;
for(int k=0;k<4;k++){
    int x=i+dx[k];
    int y=j+dy[k];
    if(x<0 || y<0 || x>=n || y>=m)
    continue;
    if(!v[x][y])
    continue;
    int p1=get(x*m+y);
    int p2=get(i*m+j);
    if(p1!=p2)
    merge(p1,p2);
}
        }
       }
        sz=0;
        unordered_set<int> s;
         int cur=0;
        for(int a=0;a<m;a++){
            if(!v[0][a])
                continue;
            int p=get(a);
            if(s.count(p))
                continue;
            s.insert(p);
            cur+=Size[p];
        }
        s.clear();
      //  cout<<cur<<" ";
         for(auto &it:q){
            if(!ans[sz]){
                sz++;
                continue;
            }
            int i=it[0];
            int j=it[1];
             v[i][j]=1;
for(int k=0;k<4;k++){
    int x=i+dx[k];
    int y=j+dy[k];
    if(x<0 || y<0 || x>=n || y>=m)
    continue; 
    if(!v[x][y])
    continue;
    
   int p1=get(x*m+y);
    int p2=get(i*m+j);
    if(p1!=p2)
    merge(p1,p2);
      
    
    
}
         int p4=0;
        for(int a=0;a<m;a++){
            if(!v[0][a])
                continue;
            int p=get(a);
            if(s.count(p))
                continue;
            s.insert(p);
           
            //cout<<p<<" "<<Size[p]<<"  ";
            p4+=Size[p];
        }
        s.clear();
             
ans[sz]=p4-cur-1;
             ans[sz]=max(0,ans[sz]);
cur=p4;
sz++;
         }
         reverse(ans.begin(),ans.end());
         return ans;

    }
};