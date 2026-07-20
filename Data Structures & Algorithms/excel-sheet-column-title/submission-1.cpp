class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber > 0){
            if(columnNumber%26 == 0){
                ans += 'Z';
                columnNumber /= 26;
                columnNumber--;
                continue;
            }
            char temp = (columnNumber%26)-1+'A';
           
            ans += temp;
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};