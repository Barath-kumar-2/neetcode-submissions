class Solution {
public:
    long long solve(vector<int>& stoneValue, int i, int j, vector<vector<long long>>& dp){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        long long temp = stoneValue[i] - solve(stoneValue, i+1, j, dp);
        long long temp2 = LLONG_MIN;
        if(i+1 <= j){
            temp2 = stoneValue[i] + stoneValue[i+1] - solve(stoneValue, i+2, j, dp);
        }
        long long temp3 = LLONG_MIN;
        if(i+2 <= j){
            temp3 = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - solve(stoneValue, i+3, j, dp);
        }
        return dp[i][j] = max({temp, temp2, temp3});
        
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        long long temp = solve(stoneValue, 0, n-1, dp);
        cout << temp << endl;
        if(temp > 0){
            return "Alice";
        }else if(temp < 0){
            return "Bob";
        }
        return "Tie";
    }
};