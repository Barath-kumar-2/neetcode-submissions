class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp = "";
        for(auto it : path){
            if(it == '/'){
                if(temp == ""){
                    continue;
                }else{
                    if(temp == ".."){
                        if(!st.empty()){
                            st.pop();
                        }
                    }else if(temp != "."){
                        st.push(temp);
                    }
                    temp = "";
                }
            }else{
                temp += it;
            }
        }
        if(temp != "/" && temp != ""){
            if(temp == ".."){
                        if(!st.empty()){
                            st.pop();
                        }
                    }else if(temp != "."){
                        st.push(temp);
                    }
        }
        
        string ans = "";
        while(!st.empty()){
            string top = st.top();
            st.pop();
            ans = '/'+top+ans;
        }
        if(ans == ""){
            return "/";
        }
        return ans;
    }
};