class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
       unordered_set<string> s; 
       vector<string> ans;
      vector<vector<string>> v(31);
       for(auto &it:words){
       //it='a'+it;
        int i=it.size();
        v[i].push_back(it);
       }
       for(int i=1;i<=30;i++){
    for(auto &it:v[i]){
        vector<int> dp(i+1);
        dp[0]=1;
//cout<<it<<" ";
for(int j=1;j<=i;j++){
    if(!dp[j-1])
    continue;
    string st;
    for(int k=j;k<=i;k++){
        st+=it[k-1];
// cout<<st<<" ";
        if(s.count(st)){
          //  cout<<i<<" "<<st<<" "<<k<<"  ";
        dp[k]=1;
    }
    }
}
if(dp[i])
ans.push_back(it);

        s.insert(it);
    }
       }

return ans;

    }
};