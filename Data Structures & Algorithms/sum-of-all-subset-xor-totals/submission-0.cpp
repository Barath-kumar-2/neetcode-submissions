class Solution {
public:
    int ans = 0;
    void solve(vector<int>& nums, int idx, int temp){
        if(idx >= nums.size()){
            ans += temp;
            return;
        }
        solve(nums, idx+1, temp);
        temp ^= nums[idx];
        solve(nums, idx+1, temp);
        temp ^= nums[idx];
    }
    int subsetXORSum(vector<int>& nums) {
        solve(nums, 0, 0);
        return ans;
    }
};