class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses,0);
        for(int i = 0; i < prerequisites.size(); i++){
            int num1 = prerequisites[i][0];
            int num2 = prerequisites[i][1];
            adj[num1].push_back(num2);
            inDegree[num2]++;
        }
        int ans = 0;
        queue<int> q;
        vector<bool> visited(numCourses,false);
        for(int i = 0; i < inDegree.size(); i++){
            if(inDegree[i] == 0){
                q.push(i);
                visited[i] = true;
                ans++;
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0 && visited[it] == false){
                    visited[it] = true;
                    q.push(it);
                    ans++;
                }
            }
        }
        return ans == numCourses;
    }
};
