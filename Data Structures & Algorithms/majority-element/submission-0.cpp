class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int ans = -1;
        for(auto it : nums){
            if(count == 0){
                ans = it;
            }
            if(ans == it){
                count++;
            }else{
                count--;
            }
        }
        return ans;
    }
};