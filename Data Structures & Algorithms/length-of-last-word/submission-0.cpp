class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int i = 0;
        while(s[i] == ' '){
            i++;
        }
        int j = s.size()-1;
        while(j >= 0 && s[j] == ' '){
            j--;
        }
        int temp = 0;
        while(i <= j){
            if(s[i] == ' '){
                res = temp;
                i++;
                temp = 0;
            }else{
                temp++;
                i++;
            }
        }
        res = temp;
        return res;
    }
};