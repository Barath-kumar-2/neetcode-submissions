class MinStack {
public:
    stack<int> st;
    stack<int> st2;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(st2.empty() || st2.top() >= val){
            st2.push(val);
        }
    }
    
    void pop() {
        int top = st.top();
        st.pop();
        if(st2.top() == top){
            st2.pop();
        }
    }
    
    int top() {
        int top = st.top();
        return top;
    }
    
    int getMin() {
        int top = st2.top();
        return top;
    }
};
