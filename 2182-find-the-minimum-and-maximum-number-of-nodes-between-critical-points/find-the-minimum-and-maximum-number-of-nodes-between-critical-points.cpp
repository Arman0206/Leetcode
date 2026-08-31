/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
       vector<int> v;
       while(head!=NULL){
        v.push_back(head->val);
        head=head->next;
       }
       vector<int> res;
       int n=v.size();
       for(int i=1;i<n-1;i++){
if(v[i]>v[i-1] && v[i]>v[i+1])
res.push_back(i);
if(v[i]<v[i-1] && v[i]<v[i+1])
res.push_back(i);
       }
       vector<int> ans;
       int maxi=0;
       int mini=n;
       int sz=res.size();
if(sz<2){
    ans.push_back(-1);
    ans.push_back(-1);
    return ans;
}
maxi=res[sz-1]-res[0];
       for(int i=1;i<sz;i++){
        mini=min(mini,res[i]-res[i-1]);
       }
    
       ans.push_back(mini);
       ans.push_back(maxi);
       return ans;




    }
};