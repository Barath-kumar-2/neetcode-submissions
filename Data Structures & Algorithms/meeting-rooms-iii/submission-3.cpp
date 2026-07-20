class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> avl;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> bsy;
        for(int i = 0; i < n; i++){
            avl.push(i);
        }
        vector<int> ans(n, 0);
        for(int i = 0; i < meetings.size(); i++){
            int now = meetings[i][0];
            while(!bsy.empty()){
                int top = bsy.top().first;
                if(top <= now){
                    avl.push(bsy.top().second);
                    bsy.pop();
                }else{
                    break;
                }
            }
            int node = -1;
            if(!avl.empty()){
                node = avl.top();
                avl.pop();
                ans[node]++;
                int end = meetings[i][1];
                bsy.push({end,node});
            }else{
                int time = bsy.top().first;
                node = bsy.top().second;
                bsy.pop();
                int dif = meetings[i][1] - now;
                bsy.push({time+dif, node});
                ans[node]++;
            }
        }
        int maxi = INT_MIN;
        int res = -1;
        for(int i = 0; i < ans.size(); i++){
            if(ans[i] > maxi){
                res = i;
                maxi = ans[i];
            }
        }
        return res;
    }
};