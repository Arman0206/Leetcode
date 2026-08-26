class Solution {
public:
int maxi;
unordered_map<int,int> mp;
vector<int> val;
vector<int> val2;
vector<int> val3;
vector<int> val4;
vector<int> v;
vector<vector<pair<int,int>>> adj;
void dfs(int node,int path,int depth,int dif,int last,int par,int chose,int chose2){
int num=v[node];
int z=val[num];
int k2=val2[num];
int k3=val3[num];//its path distance of the value 
int k4=val4[num];
if(chose && val3[num]!=0){
int z1=max(dif,val4[num]);//chosing prev
int z2=max(chose,val2[num]);//chosing current
if(z1<z2){
    dif=z1;
    last=max(last,val3[num]);
}
else{
    dif=z2;
    last=max(val[num],chose2);
}
}
else if(val3[num]>last){
    last=z;//last depth
    dif=val2[num];//last dif
}
chose=max(val4[num],chose);
chose2=max(chose2,val3[num]);
//cout<<node<<" "<<dif<<"  ";
maxi=max(maxi,path-dif);
if(mp.count(path-dif))
mp[path-dif]=min(mp[path-dif],depth-last);
else
mp[path-dif]=depth-last;
val[num]=val3[num];
val4[num]=val2[num];
val3[num]=depth;
val4[num]=path;
for(auto &it:adj[node]){
if(it.first==par)
continue;
val4[num]+=it.second;
dfs(it.first,it.second+path,depth+1,dif,last,node,chose,chose2);
val4[num]-=it.second;
}
val[num]=z;
val3[num]=k3;
val2[num]=k2;
val4[num]=k4;
}
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {

        int n=nums.size();
        v.resize(n);
        adj.resize(n);
        val.assign(5e4+1,0);
     val2.assign(5e4+1,0);
         val3.assign(5e4+1,0);
     val4.assign(5e4+1,0);
     v=nums;
        maxi=0;
        //depth should start with 1
        for(auto &it:edges) {
            adj[it[0]].push_back({it[1],it[2]});
              adj[it[1]].push_back({it[0],it[2]});
        }
dfs(0,0,1,0,0,-1,0,0);
int ans=mp[maxi];
vector<int> res={maxi,ans};
return res;

    }
};