class Solution {
public:
    bool solve(vector<int>& nums, vector<int>& dp, int index){
        if(index >= nums.size()-1){
            dp[nums.size()-1] = 1;
            return true;
        }
        if(dp[index] != -1){
            return (dp[index] == 1 ? true : false);
        }
        int count = nums[index];
        int i = index+1;
        while(count > 0){
            bool temp = solve(nums,dp, i);
            count--;
            i++;
            if(temp == true){
                dp[index] = 1;
                return true;
            }
        }
        dp[index] = -1;
        return false;

    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(nums, dp, 0);
        return (dp[n-1] == 1 ? true : false);
    }
};
