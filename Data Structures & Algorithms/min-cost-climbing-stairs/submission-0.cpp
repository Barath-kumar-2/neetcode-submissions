class Solution {
public:
    int solve(int n, vector<int>& dp, vector<int>& cost, int idx){
        if(idx >= n){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int temp1 = solve(n, dp, cost,idx+1);
        int temp2 = solve(n, dp, cost,idx+2);
        return dp[idx] = min(temp1, temp2) + (cost[idx]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(solve(n, dp, cost, 0), solve(n, dp, cost,1));
    }
};
