class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        for(auto it : nums){
            start = max(it, start);
            end += it;
        }
        int ans = 0;
        while(start <= end){
            int mid = start + (end-start)/2;
            int temp = 0;
            int count = 1;
            for(auto it : nums){
                if(temp+it <= mid){
                    temp += it;
                }else{
                    count++;
                    temp = it;
                }
            }
            if(count <= k){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};