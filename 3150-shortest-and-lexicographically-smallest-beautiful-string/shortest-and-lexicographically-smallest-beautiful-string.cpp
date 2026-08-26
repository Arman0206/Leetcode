class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
     int n=s.size();
     set<string> st;
     int cnt=0;
int x=n+1;
  string ans;
  map<int,int> mp;
  for(int i=0;i<n;i++){
        mp[cnt]=i;
    if(s[i]=='1')
    cnt++;
  
      
    if(mp.count(cnt-k)){
x=min(x,i-mp[cnt-k]+1);
    }
  
  }
  if(x==(n+1))
  return ans;
//cout<<x<<" ";

     cnt=0;
     for(int i=0;i<n;i++){
if(s[i]=='1')
cnt++;
int cur=cnt;
for(int j=0;j<=i;j++){
    if(cur<k)
    break;
    if((i-j+1)<x)
    break;
   if(cur==k && ((i-j+1)==x)){
    string s2;
    for(int k=j;k<=i;k++)
    s2+=s[k];
st.insert(s2);
break;
}

if(s[j]=='1')
cur--;
     }

    }
  
if(!st.size())
return ans;
ans=(*(st.begin()));
return ans;


    }
};