class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j = i+1; j < nums.size(); j++){
                if(j > i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                long long temp = (long long)target-(long long)(nums[i]+nums[j]);
                int k = j+1;
                int l = nums.size()-1;
                while(k < l){
                    if((nums[k]+nums[l]) == temp){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        while(k < l && nums[k] == nums[k+1]){
                            k++;
                        }
                        k++;
                    }else if(nums[k]+nums[l] < temp){
                        k++;
                    }else{
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};