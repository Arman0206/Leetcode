class Solution {
public:
vector<int> v;
vector<int> sg;
int build(int index,int l,int r){
    if(l==r)
return sg[index]=v[l]; 
    int mid=(l+r)/2;
sg[index]=max(sg[index],build(2*index,l,mid)); 
sg[index]=max(sg[index],build(2*index+1,mid+1,r)); 
return sg[index];
}
//point update
int update(int index,int l,int r,int left ,int right){
//No lazy--left=right
if(l==r)
return sg[index]=0;
int ans=0;
int mid=(l+r)/2;
 if(left<=mid){
ans=max(ans,update(2*index,l,mid,left,right)); 
    }
    if(right>mid){
ans=max(ans,update(2*index+1,mid+1,r,left,right));
    }
     return sg[index]=max(sg[2*index],sg[2*index+1]);
}
int query(int index,int l,int r,int left ,int right){
if(left<=l && right>=r)
return sg[index];
int ans=0;
int mid=(l+r)/2;
 if(left<=mid){
ans=max(ans,query(2*index,l,mid,left,right)); 
    }
    if(right>mid){
ans=max(ans,query(2*index+1,mid+1,r,left,right));
    }
    return ans;
}
    vector<int> maximumSumQueries(vector<int>& v1, vector<int>& v2, vector<vector<int>>& q2) {
    map<int,int> mp;
    int n=v1.size();
//max for each second 
    for(int i=0;i<n;i++){
        mp[v2[i]]=max(mp[v2[i]],v1[i]);
    }

map<int,vector<int>> adj;
//adj to remove during query ie set value to
for(auto &it:mp){
    adj[it.second].push_back(it.first);
    v.push_back({it.second+it.first});

    mp[it.first]=v.size()-1;
}

int x=v.size();
sg.assign(4*x,0);
build(1,0,x-1);

    int m=q2.size();

vector<vector<int>> q;

vector<int> ans(m);

for(int i=0;i<m;i++){
q.push_back({q2[i][0],q2[i][1],i});
}

sort(q.begin(),q.end());


for(auto &e:q){
    int a=e[0];
    int b=e[1];
    int ind=e[2];
    //erase--point update
    auto it=adj.begin();
    while(it!=adj.end()){
if(it->first>=a)
break;
for(auto &itt:it->second){
    update(1,0,x-1,mp[itt],mp[itt]);
}
adj.erase(it);
it=adj.begin();
    }
auto ittt=mp.lower_bound(b);
if(ittt!=mp.end())
ans[ind]=query(1,0,x-1,ittt->second,x-1);
if(!ans[ind])
ans[ind]=-1;
}
return ans;

    }
};