class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int temp = nums[i];
            nums.push_back(temp);
        }
        return nums;
    }
};