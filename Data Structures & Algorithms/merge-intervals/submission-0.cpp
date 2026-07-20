class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            int num = ans.back()[1];
            if(intervals[i][0] <= num){
                ans.back()[1] = max(num, intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
