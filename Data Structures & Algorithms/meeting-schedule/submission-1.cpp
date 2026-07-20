/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int m = intervals.size();
        vector<vector<int>> grid(m, vector<int>(2,0));
        for(int i = 0; i < intervals.size(); i++){
            int num = intervals[i].start;
            int old = intervals[i].end;
            grid[i][0] = num;
            grid[i][1] = old;
        }
        sort(grid.begin(), grid.end());
        int old = -1;
        for(int i = 0; i < grid.size(); i++){
            int num = grid[i][0];
            if(old > num){
                return false;
            }
            old = grid[i][1];
        }
        return true;
    }
};
