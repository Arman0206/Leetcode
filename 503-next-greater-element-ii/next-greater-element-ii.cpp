class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        int n=v.size();
        vector<int> ans(n,-1);
        stack<int> s;
        for(int i=0;i<2*n;i++){
            int ind=i%n;
            int x=v[ind];
            while(!s.empty()){
                int y=s.top();
if(x<=v[y])
break;
ans[y]=x;
s.pop();
            }
s.push(ind);
        }

        return ans;
    }
};