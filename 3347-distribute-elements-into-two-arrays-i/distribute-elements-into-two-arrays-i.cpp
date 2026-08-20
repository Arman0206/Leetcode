class Solution {
public:
    vector<int> resultArray(vector<int>& v) {
        vector<int> v1,v2;
        v1.push_back(v[0]);
        v2.push_back(v[1]);
        int n=v.size();
        for(int i=2;i<n;i++){
if(v1.back()>v2.back())
v1.push_back(v[i]);
else
v2.push_back(v[i]);
        }
        for(auto &it:v2)
        v1.push_back(it);
        return v1;
    }
};