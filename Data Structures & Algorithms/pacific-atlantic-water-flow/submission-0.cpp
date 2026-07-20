class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int,int>> p;
        queue<pair<int,int>> a;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> check1(m, vector<bool>(n, false));
        vector<vector<bool>> check2(m, vector<bool>(n, false));
        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                if(i == 0 || j == 0){
                    p.push({i,j});
                    check1[i][j] = true;
                }
                if((i == m-1) || (j == n-1)){
                    a.push({i,j});
                    check2[i][j] = true;
                }
            }
        }
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        while(!p.empty()){
            int r = p.front().first;
            int c = p.front().second;
            p.pop();
            for(int i = 0; i < 4; i++){
                int x = dx[i]+r;
                int y = dy[i]+c;
                if(x >= 0 && y >= 0 && x < m && y < n){
                    if(heights[x][y] >= heights[r][c] && check1[x][y] == false){
                        p.push({x,y});
                        check1[x][y] = true;
                    }
                }
            }
        }
        while(!a.empty()){
            int r = a.front().first;
            int c = a.front().second;
            a.pop();
            for(int i = 0; i < 4; i++){
                int x = dx[i]+r;
                int y = dy[i]+c;
                if(x >= 0 && y >= 0 && x < m && y < n){
                    if(heights[x][y] >= heights[r][c] && check2[x][y] == false){
                        a.push({x,y});
                        check2[x][y] = true;
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(check1[i][j] && check2[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
