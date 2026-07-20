class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(auto it : s){
            string curr = "";
            curr += it;
            if(curr == "]"){
                string temp = "";
                while(!st.empty() && st.top() !="["){
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                int k = 0;
                string ko = st.top();
                int num = ko[0]-'0';
                int digit = 1;
                while(num >=0 && num <= 9){
                    cout << ko[0] << endl;
                    k += num*digit;
                    digit*=10;
                    st.pop();
                    if(!st.empty() ){
                        ko = st.top();
                    }else{
                        break;
                    }
                    num = ko[0]-'0';
                }
                
               
                string ok = temp;
                while(k > 1){
                    temp += ok;
                    k--;
                }
                st.push(temp);
            }else{
                
                st.push(curr);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
        
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};