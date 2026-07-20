class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start = 0;
        int end = 0;
        int ans = 0;
        for(auto it : weights){
            start = max(start,it);
            end += it;
        }
        while(start <= end){
            int mid = start +(end-start)/2;
            int temp = 0;
            int count = 1;
            for(auto it : weights){
                if(temp+it <= mid){
                    temp += it;
                }else{
                    count++;
                    temp = it;
                }
            }
            if(count > days){
                start = mid+1;
            }else{
                ans = mid;
                end = mid-1;
            }
        }
        return ans;
    }
};