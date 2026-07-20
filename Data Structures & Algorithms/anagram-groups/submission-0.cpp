class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> m;
        vector<vector<string>> ans;
        for(int i = 0; i < strs.size();i++){
            string it = strs[i];
            sort(it.begin(), it.end());
            m[it].push_back(i);
        }
        for(auto it : m){
            vector<string>temp;
            for(auto ele : it.second){
                temp.push_back(strs[ele]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
