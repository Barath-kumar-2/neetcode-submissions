class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            nums.push_back(nums[i]);
        }
        int sum = 0;
        int ans = nums[0];
        int temp = 0;
        int left = 0;
        int right = 0;
        while(right < nums.size()){
            temp += nums[right];
            int len = right-left+1;
            while(len > n || (nums[left] < 0 && left < right)){
                temp -= nums[left];
                left++;
                len--;
            }
            ans = max(ans, temp);
            if(temp < 0){
                right++;
                left = right;
                temp = 0;
            }else{
                right++;
            }
        }
        return ans;
    }
};