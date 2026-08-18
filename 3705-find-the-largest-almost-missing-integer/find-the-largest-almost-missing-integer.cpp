class Solution {
public:
    int largestInteger(vector<int>& v, int k) {
    unordered_map<int,int> mp;
    int n=v.size();
    int ans=-1;
    for(int i=0;i<n;i++){
unordered_set<int> s;
int m=i+k;
if(m>n)
continue;
for(int j=i;j<m;j++){
    s.insert(v[j]);
}
for(auto &it:s)
mp[it]++;
    }
    for(auto &it:mp){
        if(it.second==1)
        ans=max(ans,it.first);
    }
    return ans;
    }
};