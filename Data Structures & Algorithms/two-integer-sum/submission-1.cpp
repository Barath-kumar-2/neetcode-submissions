class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); i++){
            int it = nums[i];
            int req = target-it;
            if(m.find(req) != m.end()){
                return {m[req], i};
            }
            m[it] = i;
        }
        return {};
    }
};
