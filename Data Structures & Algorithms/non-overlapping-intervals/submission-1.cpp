class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int res = 0;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            int num1 = intervals[i][0];
            int num2 = intervals[i][1];
            int old = ans.back()[1];
            if(num1 < old){
                res++;
                if(old >= num2){
                    ans.pop_back();
                    ans.push_back(intervals[i]);
                }
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return res;
    }
};
