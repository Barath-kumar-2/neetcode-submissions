class Solution {
public:
    int findMin(vector<int> &nums) {
        int start = 0;
        int end = nums.size()-1;
        while(start < end){
            int mid = start + (end-start)/2;
            if(nums[mid] >= nums[0]){
                start = mid+1;
            }else{
                end = mid;
            }
        }
        int ans = min({nums[0], nums[end], nums[nums.size()-1]});
        return ans;
    }
};
