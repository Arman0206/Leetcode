class Solution {
public:
    int minimumDeletions(vector<int>& v) {
        int x,x2,y,y2;
int n=v.size();
int mini=INT_MAX;
int maxi=INT_MIN;
for(int i=0;i<n;i++){
if(v[i]>maxi){
maxi=v[i];
x=i+1;
}
if(v[i]<mini){
mini=v[i];
y=i+1;
}
}
reverse(v.begin(),v.end());
for(int i=0;i<n;i++){
if(v[i]==maxi){
maxi=v[i];
x2=i+1;
}
if(v[i]==mini){
mini=v[i];
y2=i+1;
}

}

int ans=x+y2;
ans=min(ans,y+x2);
x=max(x,y);
x2=max(x2,y2);
ans=min(ans,x);
ans=min(ans,x2);
return ans;

    }
};