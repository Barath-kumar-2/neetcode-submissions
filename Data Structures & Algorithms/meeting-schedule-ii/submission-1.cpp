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
        if(v.size() == 0){
            return 0;
        }
        sort(v.begin(), v.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 1;
        int num = v[0][1];
        pq.push(num);
        for(int i = 1; i < v.size(); i++){
            int curr = v[i][0];
            if(pq.empty()){
                pq.push(v[i][1]);
            }else{
                int top = pq.top();
                if(top > curr){
                    pq.push(v[i][1]);
                    ans++;
                }else{
                    pq.pop();
                    pq.push(v[i][1]);
                }
            }
        }
        return ans;
    }
};
