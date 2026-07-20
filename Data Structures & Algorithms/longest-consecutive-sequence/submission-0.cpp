class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto it : nums){
            s.insert(it);
        }
        int ans = 0;
        for(int j = 0; j < nums.size(); j++){
            int num = nums[j];
            if(s.find(num-1) == s.end()){
                int temp = 0;
                while(s.find(num) != s.end()){
                    temp++;
                    num++;
                }
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};
