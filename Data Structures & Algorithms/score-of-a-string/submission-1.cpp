class Solution {
public:
    int scoreOfString(string s) {
        int res = 0;
        for(int i = 0; i < s.size()-1; i++){
            int num1 = s[i]-'a';
            int num2 = s[i+1]-'a';
            int temp = abs(num1-num2);
            res += temp;
        }
        return res;
    }
};