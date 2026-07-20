class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    grid[i][j] = -1;
                    break;
                }
            }
            if(!q.empty()){
                break;
            }
        }
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int temp = 0;
            // up
            if(row > 0 && (grid[row-1][col] == 1 || grid[row-1][col] == -1)){
                if(grid[row-1][col] == 1){
                    q.push({row-1,col});
                    grid[row-1][col] = -1;
                }
                temp++;
            }
            if(row < grid.size()-1 && (grid[row+1][col] == 1 || grid[row+1][col] == -1)){
                if(grid[row+1][col] == 1){
                    q.push({row+1,col});
                    grid[row+1][col] = -1;
                }
                temp++;
            }
            if(col > 0 && (grid[row][col-1] == 1 || grid[row][col-1] == -1)){
                if(grid[row][col-1] == 1){
                    q.push({row,col-1});
                    grid[row][col-1] = -1;
                }
                temp++;
            }
            if(col < grid[0].size()-1 && (grid[row][col+1] == 1 || grid[row][col+1] == -1)){
                if(grid[row][1+col] == 1){
                    q.push({row,1+col});
                    grid[row][1+col] = -1;
                }
                temp++;
            }
            ans += (4-temp);
        }
        return ans;
    }
};