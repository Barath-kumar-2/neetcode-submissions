class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i = 1;
        int n = nums.size();
        vector<int> fut(n,1);
        for(int j = n-1; j >= 0; j--){
            fut[j] = i;
            i *= nums[j];
        }
        i = 1;
        vector<int> ans(n,1);
        for(int j = 0; j < n; j++){
            ans[j] = i*fut[j];
            i *= nums[j];
        }
        return ans;
    }
};
