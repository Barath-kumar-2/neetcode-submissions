class Solution {
public:
    int minSwaps(string s) {
        stack<char> st1;
        stack<char> st2;
        for(auto it : s){
            if(it == '['){
                st1.push(it);
            }
            if(it == ']'){
                if(!st1.empty()){
                    st1.pop();
                }else{
                    st2.push(it);
                }   
            }
        }
        int num1 = st1.size();
        int num2 = st2.size();
        int ans = num1+num2;
        if(ans == 0){
            return 0;
        }else if(ans == 2){
            return 1;
        }else{
           ans = num1;
           ans += 1;
           ans /= 2;
        }
        return ans;
    }
};