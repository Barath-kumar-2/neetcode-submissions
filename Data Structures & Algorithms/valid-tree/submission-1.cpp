class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            int num1 = edges[i][0];
            int num2 = edges[i][1];
            adj[num1].push_back(num2);
            adj[num2].push_back(num1);
        }
        queue<pair<int,int>> q;
        q.push({0,-1});
        vector<bool> visited(n,false);
        visited[0] = true;
        while(!q.empty()){
            int node  = q.front().first;
            int par = q.front().second;
            q.pop();
            for(auto it : adj[node]){
                if(visited[it] == true && it != par){
                    return false;
                }
                if(visited[it] == false){
                    q.push({it,node});
                    visited[it] = true;
                }
            }
        }
        for(auto it : visited){
            if(it == false){
                return it;
            }
        }
        return true;
    }
};
