class Solution {
public:
    bool check(vector<int>& flowerbed, int idx){
        if(idx > 0 && flowerbed[idx-1] == 1){
           return false;
        }
        if(idx < flowerbed.size()-1 && flowerbed[idx+1] == 1){
            return false;
        }
        return true;
    }
    int solve(vector<int>& flowerbed, int idx, vector<int>& dp){
        if(idx >= flowerbed.size()){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        if(flowerbed[idx] == 1){
            return dp[idx] = solve(flowerbed, idx+1, dp);
        }
        int take = 0;
        int ntake = 0;
        if(check(flowerbed, idx)){
            flowerbed[idx] = 1;
            take = 1 + solve(flowerbed, idx+1, dp);
            flowerbed[idx] = 0;
        }
        ntake = solve(flowerbed, idx+1, dp);
        return dp[idx] = max(take, ntake);
    }
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        vector<int> dp(flowerbed.size(), -1);
        int temp = solve(flowerbed, 0, dp);
        return temp >= n;
    }
};