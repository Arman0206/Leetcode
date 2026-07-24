class Solution {
public:
int depth;
 string target;
    unordered_set<string> se;
       unordered_map<string,int> mp;
    int ladderLength(string s, string t, vector<string>& v) {
         v.push_back(s);
        int n=v.size();
        depth=0;
for(auto &it:v){
    se.insert(it);
}
    queue<pair<string,int>> q;
      q.push({s,1});
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
   return depth;


    }
};