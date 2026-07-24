class Solution {
public:
    int solve(string s, int i, int j, int& len){
        cout << i << endl;
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            i--;
            j++;
        }
        len = j-i-1;
        cout << len << ","<< i << "," << j <<  endl;
        return i+1;
    }
    string longestPalindrome(string s) {
        int maxLen = 0;
        int start = -1;
        for(int i = 0; i < s.size(); i++){
            int len = 0;
            int temp1 = solve(s, i, i, len);
            if(len > maxLen){
                maxLen = len;
                start = temp1;
            }
            len = 0;
            int temp2 = solve(s, i, i+1, len);
            if(len > maxLen){
                maxLen = len;
                start = temp2;
            }
        }
        
        string res = s.substr(start, maxLen);
        return res;
    }
};
