class Solution {
public:
    bool check(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int p1 = 0;
        int p2 = s.size()-1;
        while(p1 < p2){
            if(s[p1] == s[p2]){
                p1++;
                p2--;
            }else{
                if(check(s,p1+1, p2) || check(s,p1,p2-1)){
                    return true;
                }
                return false;
            }
        }
        return true;
    }
};