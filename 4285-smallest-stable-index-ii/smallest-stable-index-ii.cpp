class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> suf(n);
        for (int i = 0; i<n; i++) {
            if (i == 0) {
                pre[i] = nums[i];
            }
            else {
                pre[i] = max(nums[i], pre[i-1]);
            }
        }
        for (int i = n-1; i>=0; i--) {
            if (i == n-1) {
                suf[i] = nums[i];
            }
            else {
                suf[i] = min(nums[i], suf[i+1]);
            }
        }
        for (int i = 0; i<n; i++) {
            if (pre[i] - suf[i]<=k) {
                return i;
            }
        }
        return -1;
    }
};