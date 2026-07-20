class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> adj(numCourses);
        vector<int>inDegree(numCourses,0);
        for(int i = 0; i < prerequisites.size();i++){
            int num1 = prerequisites[i][0];
            int num2 = prerequisites[i][1];
            inDegree[num1]++;
            adj[num2].push_back(num1);
        }
        queue<int> q;
        for(int i = 0; i < inDegree.size(); i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(ans.size() == numCourses){
            return ans;
        }
        return {};
    }
};
