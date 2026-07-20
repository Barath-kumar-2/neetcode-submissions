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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<vector<int>> v;
        for(int i = 0; i < intervals.size(); i++){
            int num1 = intervals[i].start;
            int num2 = intervals[i].end;
            v.push_back({num1,num2});
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i = 0; i < v.size(); i++){
            int num2 = v[i][1];
            int num1 = v[i][0];
            if(pq.empty() || num1 < pq.top()){
                pq.push(num2);
                ans++;
            }else{
                pq.pop();
                pq.push(num2);
            }
        }
        return ans;
    }
};
