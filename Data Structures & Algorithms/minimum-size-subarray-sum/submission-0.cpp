class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int left = 0;
        int right = 0;
        int temp = 0;
        while(right < nums.size()){
            temp += nums[right];
            while(temp >= target){
                int len = right-left+1;
                ans = min(ans,len);
                temp -= nums[left];
                left++;
            }
            right++;
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};