class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int req = n*(n+1)/2;
        int curr = 0;
        for(auto it : nums){
            curr += it;
        }
        int ans = req-curr;
        return ans;
    }
};
