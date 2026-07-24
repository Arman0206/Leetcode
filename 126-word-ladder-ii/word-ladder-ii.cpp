class Solution {
public:
 vector<vector<string>> ans;
 int depth;
 string target;
    unordered_set<string> se;
       unordered_map<string,int> mp;
        vector<string> res;
        
void dfs(string st,int level){
res.push_back(st);
if(st==target){
    ans.push_back(res);
    res.pop_back();
    return;
}
int x=st.size();
for(int i=0;i<x;i++){
    for(char c='a';c<='z';c++){
string next=st;
next[i]=c;
if(mp.count(next) && (mp[next]==level-1 )){
dfs(next,level-1);
}
    }
}
res.pop_back();
}

    vector<vector<string>> findLadders(string s, string t, vector<string>& v) {
        target=s;
        v.push_back(s);
        int n=v.size();
        depth=n+2;
for(auto &it:v){
    se.insert(it);
}
    queue<pair<string,int>> q;
      q.push({s,0});
      mp[s]=0;
      while(!q.empty()){
string st=q.front().first;
int level=q.front().second;
//cout<<st<<" "<<level<<"  ";
q.pop();
int x=st.size();
for(int i=0;i<x;i++){
    for(char c='a';c<='z';c++){
string next=st;
next[i]=c;

if(se.count(next) && !mp.count(next)){
    mp[next]=level+1;
    if(next==t){
        depth=level+1;
        break;
    }
q.push({next,level+1});
}
if(mp.count(t))
break;
    }
    if(mp.count(t))
break;
}
if(mp.count(t))
break;
      }
      if(depth==n+2)
      return ans;
     dfs(t,depth);
     for(auto &it:ans)
     reverse(it.begin(),it.end());
      return ans;


        
    }
};