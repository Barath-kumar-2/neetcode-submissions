class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0;
        int maxi = 0;
        for(auto it : s){
            if(it == '('){
                mini++;
                maxi++;
            }else if(it == ')'){
                mini = max(0, mini-1);
                maxi--;
            }else{
                mini = max(0, mini-1);
                maxi++;
            }
            if(maxi < 0){
                return false;
            }
        }
        return mini == 0;
    }
};