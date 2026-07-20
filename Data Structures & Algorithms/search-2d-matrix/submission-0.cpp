class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // find the row
        int start = 0;
        int end = matrix.size()-1;
        int col = matrix[0].size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            int num = matrix[mid][col];
            if(num == target){
                return true;
            }else if(num > target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        int row = start;
        if(row < 0 || row >= matrix.size()){
            return false;
        }
        start = 0;
        end = col;
        while(start <= end){
            int mid = start+(end-start)/2;
            int num = matrix[row][mid];
            if(num == target){
                return true;
            }else if(num > target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return false;
    }
};
