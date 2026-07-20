class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        for(int i = 0; i < s.size()-1; i++){
            int num = s[i];
            int num2 = s[i+1];
            ans += abs(num-num2);
        }
        return ans;
    }
};