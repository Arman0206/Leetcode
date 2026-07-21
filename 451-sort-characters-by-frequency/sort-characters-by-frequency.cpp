class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(auto &it:s){
            mp[it]++;
        }
        multimap<int,char> mp2;
        for(auto &it:mp){
            mp2.insert({-it.second,it.first});
        }
        string ans;
        for(auto &it:mp2){
           int sz=-it.first;
            char c=it.second;
            cout<<sz<<" ";
            for(int i=0;i<sz;i++)
            ans+=c;
        }
        return ans;
    }
};