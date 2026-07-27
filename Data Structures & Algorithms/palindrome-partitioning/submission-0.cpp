class Solution {
public:
    bool check(string curr){
        string temp = curr;
        reverse(temp.begin(), temp.end());
        return temp == curr;
    }
    void solve(string& s, vector<vector<string>>& ans, vector<string>& temp, int idx){
        if(idx == s.size()){
            ans.push_back(temp);
            return;
        }
        string curr = "";
        for(int i = idx; i < s.size(); i++){
            curr += s[i];
            if(check(curr)){
                temp.push_back(curr);
                solve(s, ans, temp, i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s, ans, temp, 0);
        return ans;
    }
};

