class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        queue<pair<pair<int,int>, int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
            }
        }
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;
            q.pop();
            ans = max(ans, time);
            for(int i = 0; i < 4; i++){
                int x  = dx[i]+r;
                int y = dy[i]+c;
                if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1){
                    q.push({{x,y},time+1});
                    grid[x][y] = 2;
                }
            }
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return ans;
    }
};
