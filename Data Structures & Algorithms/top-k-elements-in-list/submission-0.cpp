class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        priority_queue<pair<int,int>> pq;
        for(auto it : nums){
            m[it]++;
        }
        for(auto it : m){
            pq.push({it.second,it.first});
        }
        vector<int> ans;
        while(k > 0){
            int num = pq.top().second;
            pq.pop();
            k--;
            ans.push_back(num);
        }
        return ans;
    }
};
