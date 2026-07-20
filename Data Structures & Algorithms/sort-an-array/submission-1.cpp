class Solution {
public:
    int find(vector<int>& nums, int start, int end){
        int pivot = nums[start];
        int left = start;
        int right = end;
        while(left < right){
            while(left < end && nums[left] <= pivot){
                left++;
            }
            while(start < right && nums[right] > pivot){
                right--;
            }
            if(left < right){
                swap(nums[left],nums[right]);
            }
        }
        swap(nums[right],nums[start]);
        return right;
    }
    void solve(vector<int>& nums, int start, int end){
        if(start >= end){
            return;
        }
        int pIndex = find(nums,start,end);
        solve(nums,start,pIndex-1);
        solve(nums,pIndex+1,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size()-1;
        solve(nums,0,n);
        return nums;
    }
};