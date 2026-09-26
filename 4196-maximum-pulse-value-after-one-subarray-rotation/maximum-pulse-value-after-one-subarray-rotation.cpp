class Solution {
public:
using ll=long long;
    long long maxValue(vector<int>& v) {
        set<ll> e,o;
        ll cur=0;
        o.insert(0);
        int n=v.size();
        ll ans=0;
        ll mini=0;
        for(int i=0;i<n;i++){
           
if(i&1){
    cur-=v[i];
auto it=o.begin();
if(it!=o.end()){
mini=min(mini,cur+*it);
}
o.insert(-cur);
}
else{
      cur+=v[i];
auto it=e.begin();
if(it!=e.end()){
mini=min(mini,cur+*it);
}
e.insert(-cur);
}
        }
return cur-2*mini;
    }
};