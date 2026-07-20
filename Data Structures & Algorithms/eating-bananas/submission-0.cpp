class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 0;
        int start = 1;
        int end = 0;
        for(auto it : piles){
            end = max(end,it);
        }
        while(start <= end){
            int mid = start + (end-start)/2;
            int temp = 0;
            for(auto it : piles){
                if(it%mid == 0){
                    temp += it/mid;
                }else{
                    temp += (it/mid+1);
                }
            }
            if(temp > h){
                start = mid+1;
            }else{
                ans = mid;
                end = mid-1;
            }
        }
        return ans;
    }
};
