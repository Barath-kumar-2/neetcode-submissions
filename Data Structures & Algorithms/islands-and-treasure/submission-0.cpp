class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0)q.push({i,j});
                
            }
        }
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int x  = dx[i]+r;
                int y = dy[i]+c;
                if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] != -1){
                    if(grid[x][y] > grid[r][c]+1){
                        grid[x][y] = grid[r][c]+1;
                        q.push({x,y});
                    }
                }
            }
        }

    }
};
