class FreqStack {
public:
    map<int, stack<int>> m1;
    unordered_map<int,int> m2;
    FreqStack() {
        
    }
    
    void push(int val) {
        if(m2.find(val) != m2.end()){
            int old = m2[val];
            m2[val]++;
            int curr = m2[val];
            m1[curr].push(val);
        }else{
            m1[1].push(val);
            m2[val] = 1;
        }
    }
    
    int pop() {
        int old = m1.rbegin()->first;
        int freq = m1.rbegin()->second.top();
        m1.rbegin()->second.pop();
        if(m1.rbegin()->second.empty()){
            m1.erase(old);
        }
        m2[freq]--;
        return freq;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */