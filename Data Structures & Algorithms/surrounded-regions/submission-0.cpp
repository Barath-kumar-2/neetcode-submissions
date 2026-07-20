class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((board[i][j] == 'O') && ((i == 0) || (j == 0) || (i == m-1) || (j == n-1))){
                    q.push({i,j});
                    board[i][j] = '.';
                }
            }
        }
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int x = dx[i]+r;
                int y = dy[i]+c;
                if(x >= 0 && y >= 0 && x < m && y < n && board[x][y] == 'O'){
                    q.push({x,y});
                    board[x][y] = '.';
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '.'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
