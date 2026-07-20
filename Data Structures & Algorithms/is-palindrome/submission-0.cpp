class Solution {
public:
    bool isPalindrome(string s) {
        int p1 = 0;
        int p2 = s.size()-1;
        while(p1 < p2){
            while(p1 < p2 && !isalnum(s[p1])){
                p1++;
            }while(p1 < p2 && !isalnum(s[p2])){
                p2--;
            }
            int num1 = 0;
            int num2 = 0;
            if(s[p1] >= 'a' && s[p1] <= 'z'){
                num1 = s[p1]-'a';
            }
            if(s[p1] >= 'A' && s[p1] <= 'Z'){
                num1 = s[p1] - 'A';
            }
            if(s[p2] >= 'a' && s[p2] <= 'z'){
                num2 = s[p2]-'a';
            }
            if(s[p2] >= 'A' && s[p2] <= 'Z'){
                num2 = s[p2] - 'A';
            }
            if((s[p1] >= '0' && s[p1] <= '9') || (s[p2] >= '0' && s[p2] <= '9')){
                if(s[p1] != s[p2]){
                    return false;
                }
            }
            if(num1 != num2){
                return false;
            }
            p1++;
            p2--;
        }
        return true;
    }
};
