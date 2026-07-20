class Solution {
public:
    int solve(vector<vector<int>>& grid, int row, int col){
        queue<pair<int,int>> q;
        q.push({row,col});
        grid[row][col] = 0;
        int temp = 1;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if(r > 0 && grid[r-1][c] == 1){
                q.push({r-1,c});
                grid[r-1][c] = 0;
                temp++;
            }
            if(c > 0 && grid[r][c-1] == 1){
                q.push({r,c-1});
                grid[r][c-1] = 0;
                temp++;
            }
            if(c < grid[0].size()-1 && grid[r][c+1] == 1){
                q.push({r,c+1});
                grid[r][c+1] = 0;
                temp++;
            }
            if(r < grid.size()-1 && grid[r+1][c] == 1){
                q.push({r+1,c});
                grid[r+1][c] = 0;
                temp++;
            }
        }
        return temp;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int temp = solve(grid, i, j);
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};
