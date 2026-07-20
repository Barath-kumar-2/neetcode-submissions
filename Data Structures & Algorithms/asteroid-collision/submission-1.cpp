class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        for(auto it : asteroids){
            if(it > 0){
                st.push(it);
            }else{
                int curr = abs(it);
                while(!st.empty() && st.top() < curr && st.top() > 0){
                    st.pop();
                }
                if(st.empty() || st.top() < 0){
                    st.push(it);
                }else if(st.top() == curr){
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};