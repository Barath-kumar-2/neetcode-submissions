class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int last = prices[0];
        for(int i = 1; i < prices.size(); i++){
            int temp = prices[i];
            if(last > temp){
                last = temp;
            }else{
                int dif = temp-last;
                ans += dif;
            }
            last = temp;
        }
        return ans;
    }
};