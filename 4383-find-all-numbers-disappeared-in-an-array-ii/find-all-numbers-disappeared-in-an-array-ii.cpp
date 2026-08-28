class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& v, int l, int r) {
        set<int> s;
        for(auto &it:v)
        s.insert(it);
      int i=l;
      vector<vector<int>> ans;
      while(i<=r){
auto it=s.lower_bound(i);
if(it==s.end()){
vector<int> res={i,r};
ans.push_back(res);
break;
}
if((*it)==i){
    i++;
    continue;
}
int k=min(r,(*it)-1);
vector<int> res={i,k};
ans.push_back(res);
i=(*it)+1;
      }
      return ans;
    }
};