class Solution {
public:
    bool check(vector<vector<char>>& board, int row, int col){
        int sr = (row/3)*3;
        int sc = (col/3)*3;
        int er = sr+2;
        int ec = sc+2;
        for(int i = sr; i <= er; i++){
            for(int j = sc; j <= ec; j++){
                if(i == row && j == col){
                    continue;
                }
                if(board[i][j] == board[row][col]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] != '.'){
                    for(int k = 0; k < board.size();k++){
                        if(k != i && board[i][j] == board[k][j]){
                            return false;
                        }
                        if(k != j && board[i][j] == board[i][k]){
                            return false;
                        }
                    }
                    bool flag = check(board, i, j);
                    if(flag == false){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};