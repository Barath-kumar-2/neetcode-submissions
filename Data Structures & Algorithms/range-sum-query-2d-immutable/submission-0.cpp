class NumMatrix {
public:
    vector<vector<int>> pSum;
    int m = 0;
    int n = 0;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        pSum.resize(m+1, vector<int>(n+1, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                pSum[i+1][j+1] = matrix[i][j] + (pSum[i+1][j] + pSum[i][j+1]) -(pSum[i][j]);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int num1 = pSum[row2+1][col2+1];
        int num2 = pSum[row2+1][col1];
        int num3 = pSum[row1][col1];
        int num4 = pSum[row1][col2+1];
        int ans = num1-num2-num4+num3;
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
 