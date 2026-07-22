class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            int temp = 0;
            while(i < nums.size() && nums[i] == 1){
                temp++;
                i++;
            }
            res = max(res, temp);
        }
        return res;
    }
};