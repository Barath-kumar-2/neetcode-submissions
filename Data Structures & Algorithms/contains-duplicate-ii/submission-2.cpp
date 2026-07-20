class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        bool flag = false;
        for(int i = 0; i < nums.size(); i++){
            if(m.find(nums[i]) != m.end()){
                int old = m[nums[i]];
                if(i-old > k){
                    flag = false;
                }else{
                    flag = true;
                }
            }
            m[nums[i]] = i;
        }
        return flag;
    }
};