class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it : tokens){
            if(it == "+"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num1+num2);
            }else if(it == "*"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num1*num2);
            }else if(it == "-"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2-num1);
            }else if(it == "/"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2/num1);
            }else{
                int num1 = stoi(it);
                st.push(num1);
            }
        }
        return st.top();
    }
};
