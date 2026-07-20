class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // building adjacenecy list
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            int ele1 = edges[i][0];
            int ele2 = edges[i][1];
            adj[ele1].push_back(ele2);
            adj[ele2].push_back(ele1);
        }
        vector<int> visited(n,0);
        int ans = 0;
        for(int i = 0; i < visited.size(); i++){
            if(visited[i] == 0){
                ans++;
            }
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                visited[node] = 1;
                for(auto it : adj[node]){
                    if(visited[it] == 0){
                        q.push(it);
                    }
                }
            }
        }
        return ans;
    }
};
