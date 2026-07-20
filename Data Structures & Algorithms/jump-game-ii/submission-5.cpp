class Solution {
public:
    int solve(vector<int>& nums,  int index, int past){
        if(index >= nums.size()-1){
            return past;
        }
        
        int count = nums[index];
        int i = index+1;
        int curr = INT_MAX;
        while(count > 0){
            int temp = solve(nums,i,past+1);
            curr = min(temp, curr);
            count--;
            i++;
        }
        return curr;

    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        return solve(nums,0, 0);
    }
};
