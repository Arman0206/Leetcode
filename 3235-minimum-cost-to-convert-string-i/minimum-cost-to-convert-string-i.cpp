class Solution {
public:
    long long minimumCost(string s, string t, vector<char>& o, vector<char>& c, vector<int>& co) {
        int n=o.size();
       vector<vector<long long>> v(26,vector<long long>(26,LLONG_MAX));
       for(int i=0;i<n;i++){
        int x=(o[i]-'a');
        int y=(c[i]-'a');
        long long z=co[i];
    v[x][y]=min(v[x][y],z);
       }
       for(int k=0;k<26;k++){
        for(int i=0;i<26;i++){
for(int j=0;j<26;j++)
{
    if(i==j){
        v[i][j]=0;
        continue;
    }

if(v[i][k]==LLONG_MAX || v[k][j]==LLONG_MAX || i==k || j==k)
continue;
v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
}
}    }
n=s.size();
long long ans=0;
for(int i=0;i<n;i++){
  int x=(s[i]-'a');
        int y=(t[i]-'a');
        if(v[x][y]==LLONG_MAX){
           // cout<<x<<" "<<y<<"  ";
        return -1;
        }
        ans+=v[x][y];
}


return ans;



    }
};