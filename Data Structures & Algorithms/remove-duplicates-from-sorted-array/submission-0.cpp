class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 0;
        for(int k = 1; k < nums.size(); k++){
            if(nums[i] != nums[k]){
                i++;
                nums[i] = nums[k];
            }
        }
        return (i+1);
    }
};