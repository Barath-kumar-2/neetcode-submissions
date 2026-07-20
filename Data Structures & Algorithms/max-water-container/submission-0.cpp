class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size()-1;
        int ans = 0;
        while(i < j){
            int dist = j-i;
            int temp = min(heights[i], heights[j]);
            int curr = temp*dist;
            ans = max(ans, curr);
            if(heights[i] == temp){
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};
