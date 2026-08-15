class Solution {
public:
    int longestSubsequence(vector<int>& v) {
       int ans=0;
       int n=v.size();
       int first=n;
       int cur=0;
       for(int i=0;i<n;i++){
        cur^=v[i];
        if(cur){
            ans=max(ans,n-1);
            ans=max(ans,i+1);
            first=min(first,i);
        }
        else{
            ans=max(ans,i-first);
        }
       }
       return ans;
    }
};