class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = INT_MAX;
        int num2 = INT_MAX;
        int count1 = 0;
        int count2 = 0;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(count1 == 0 && nums[i] != num2){
                num1 = nums[i];
            }else if(count2 == 0 && nums[i] != num1){
                num2 = nums[i];
            }
            if(num1 == nums[i]){
                count1++;
            }
            else if(num2 == nums[i]){
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(auto it : nums){
            if(it == num1){
                count1++;
            }else if(it == num2){
                count2++;
            }
        }
        if(count1 > n/3 && count2 > n/3){
            return {num1,num2};
        }
        if(count2 > n/3){
            return {num2};
        }
        if(count1 > n/3){
            return {num1};
        }
        return {};
        
    }
};