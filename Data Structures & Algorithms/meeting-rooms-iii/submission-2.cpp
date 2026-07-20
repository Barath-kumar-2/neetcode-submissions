class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> ans(n,0);
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> avl;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> busy;
        for(int i = 0; i < n; i++){
            avl.push(i);
        }
        for(int i = 0; i < meetings.size(); i++){
            int start = meetings[i][0];
            int end = meetings[i][1];
            while(!busy.empty() && busy.top().first <= start){
                avl.push(busy.top().second);
                busy.pop();
            }
            if(!avl.empty()){
                int room = avl.top();
                ans[room]++;
                avl.pop();
                busy.push({end, room});
            }else{
                int time = busy.top().first;
                int room = busy.top().second;
                busy.pop();
                time += (end-start);
                busy.push({time,room});
                ans[room]++;
            }
        }
        int res = 0;
        int mini = INT_MIN;
        for(int i = 0; i < n; i++){
            if(ans[i] > mini){
                mini = ans[i];
                res = i;
            }
        }
        return res;
    }
};