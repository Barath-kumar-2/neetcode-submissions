class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto it : arr){
            int dif = abs(x-it);
            pq.push({dif,it});
        }
        vector<int> ans;
        while(k > 0){
            int node = pq.top().second;
            pq.pop();
            ans.push_back(node);
            k--;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};