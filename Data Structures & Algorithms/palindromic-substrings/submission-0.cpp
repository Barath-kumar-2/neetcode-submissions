class Solution {
public:
    int ans = 0;
    void solve(string s, int i, int j){
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            i--;
            j++;
            ans++;
        }
    }
    int countSubstrings(string s) {

        for(int i = 0; i < s.size(); i++){
            solve(s, i, i);
            solve(s, i, i+1);
        }
        return ans;
    }
};

