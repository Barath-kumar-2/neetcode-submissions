class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = 0;
        int ans = 0;
        while(right < nums.size()){
            int temp = nums[right];
            if(temp == val){
                right++;
            }else{
                nums[left] = nums[right];
                left++;
                right++;
                ans++;
            }
        }
        return ans;

    }
};