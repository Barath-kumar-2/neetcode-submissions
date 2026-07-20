class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int ans = 0;
        int sum =0;
        m[0] = 1;
        for(auto it : nums){
            sum += it;
           
            int req = sum - k;
            if(m.find(req) != m.end()){
                ans += m[req];
            }
            m[sum]++;
        }
        return ans;
    }
};