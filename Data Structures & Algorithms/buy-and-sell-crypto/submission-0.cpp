class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr = prices[0];
        int ans = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > curr){
                int temp = prices[i]-curr;
                ans = max(ans, temp);
            }else{
                curr = prices[i];
            }
        }
        return ans;
    }
};
