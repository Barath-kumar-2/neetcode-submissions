class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = 0;
        int mini = 1e8;
        for(auto it : strs){
            int temp = it.size();
            mini = min(temp,mini);
        }
        string ans = "";
        for(int i = 0; i < mini; i++){
            char ch = strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                if(ch != strs[j][i]){
                    return ans;
                }
            }
            ans += ch;
        }
        return ans;
    }
};