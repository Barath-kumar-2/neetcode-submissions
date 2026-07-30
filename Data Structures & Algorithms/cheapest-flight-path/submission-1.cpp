class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : flights){
            int node1 = it[0];
            int node2 = it[1];
            int wt = it[2];
            adj[node1].push_back({node2, wt});
        }
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {0, src}});
        vector<vector<int>> dp(n+1, vector<int>(k+2, INT_MAX));
        while(!pq.empty()){
            int curr = pq.top().first;
            int stop = pq.top().second.first;
            int node = pq.top().second.second;
            pq.pop();
            if(node == dst && stop <= (k+1)){
                return curr;
            }
            if(stop > k){
                continue;
            }
            for(auto it : adj[node]){
                int ele = it.first;
                int temp = it.second;
                if((dp[ele][stop+1] > curr+temp) && (stop+1 <= k+1)){
                    dp[ele][stop+1] = curr+temp;
                    pq.push({curr+temp, {stop+1, ele}});
                }
            }
        }
        return -1;
    }
};
