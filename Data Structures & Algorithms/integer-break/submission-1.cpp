class Solution {
public:
    int solve(int n, int curr, vector<int>& dp){
        if(curr == n){
            return 1;
        }
        if(dp[curr] != -1){
            return dp[curr];
        }
        int maxi = INT_MIN;
        for(int i = 1; i <= 9; i++){
            int temp = curr+i;
            int pre = 0;
            if(temp <= n){
                pre = solve(n, temp, dp) * i;
            }
            maxi = max(maxi, pre);
        }
        return dp[curr] = maxi;
    }
    int integerBreak(int n) {
        if(n <= 3){
            return n-1;
        }
        vector<int> dp(n+1, -1);
        return solve(n, 0, dp);
    }
};