class Solution {
public:
map<pair<int,int>,int> mp;
int n,k;
vector<int> req;
int fun(int last,int cur){
    if(last==((1<<n)-1))
    return 0;
    int check=last|cur;
     if(check==((1<<n)-1))
    return 1;
    if(mp.count({last,cur}))
    return mp[{last,cur}];
    int ans=n+1;
    int c=0;
    int z=__builtin_popcount(cur);
if(z==k)
return mp[{last,cur}]=1+fun(last|cur,0);
    for(int i=0;i<n;i++){
        if((last & (1<<i)) || (cur & (1<<i)))
        continue;
        if((req[i] & last )!=req[i])
        continue;
    c++;
        int mask=cur|(1<<i);
        ans=min(ans,fun(last,mask));
       
    }
    if(!c)
    return mp[{last,cur}]=1+fun(last|cur,0);
  
    return mp[{last,cur}]=ans;
}
    int minNumberOfSemesters(int n2, vector<vector<int>>& v, int k2) {
        n=n2;
        k=k2;
        req.resize(n);
        for(auto &it:v){
            it[0]--;
            it[1]--;
            req[it[1]]|=(1<<it[0]);
        }
        return fun(0,0);
    }
};