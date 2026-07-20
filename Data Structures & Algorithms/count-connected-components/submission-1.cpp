class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        int ans = 0;
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        for(int i = 0; i < n; i++){
            queue<int> q;
            if(visited[i] == false){
                q.push(i);
                ans++;
            }
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto it : adj[node]){
                    if(visited[it] == false){
                        visited[it] = true;
                        q.push(it);
                    }
                }
            }
        }
        return ans;
    }
};
