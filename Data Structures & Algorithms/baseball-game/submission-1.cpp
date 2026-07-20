class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int ans = 0;
        for(auto it : operations){
            if(it == "+"){
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.pop();
                st.push(top2);
                st.push(top1);
                int ele = top1+top2;
                ans += ele;
                st.push(ele);
            }else if(it == "D"){
                int top = st.top();
                int ele = 2*top;
                ans += ele;
                st.push(ele);
            }else if(it == "C"){
                ans -= st.top();
                st.pop();
            }else{
                int ele = stoi(it);
                ans += ele;
                st.push(ele);
            }
        }
        return ans;
    }
};