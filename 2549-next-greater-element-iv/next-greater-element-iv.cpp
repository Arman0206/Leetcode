class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& v) {
        int n=v.size();
        vector<int> ans(n,-1);
        vector<vector<int>> adj(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()){
                int x=st.top();
                if(v[x]>=v[i])
                break;
                 st.pop();
           
                adj[i].push_back(x);
            }
           st.push(i);
        }
          while(!st.empty())
          st.pop();
        for(int i=0;i<n;i++){
 while(!st.empty()){
                int x=st.top();
          // cout<<i<<" "<<x<<"  ";
                if(v[x]>=v[i])
                break;
                 st.pop();
               ans[x]=v[i];
            }
            reverse(adj[i].begin(),adj[i].end());
for(auto &it:adj[i])
st.push(it);
        }
return ans;
    }
};