class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n,-1);
        vector<int> nse(n,n);
        stack<int> st;
        // filling pse
        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i] = -1;
            }else{
                pse[i] = st.top();
            }
            st.push(i);
        }
        // filling nse
        while(!st.empty()){
            st.pop();
        }
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i] = n;
            }else{
                nse[i] = st.top();
            }
            st.push(i);
        }
        int ans = 0;
        cout << nse[n-1] << endl;
        for(int i = 0; i < heights.size(); i++){
            int len = nse[i]-pse[i]-1;
            int temp = heights[i]*len;
            ans = max(ans,temp);
        }
        return ans;
    }
};
