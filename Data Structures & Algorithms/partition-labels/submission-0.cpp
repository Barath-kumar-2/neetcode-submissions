class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        for(int i = s.size()-1; i >= 0; i--){
            if(m.find(s[i]) == m.end()){
                m[s[i]] = i;
            }
        }
        vector<int> ans;
        int left = 0;
        int right = 0;
        int maxi = -1;
        while(right < s.size()){
            maxi = max(maxi,m[s[right]]);
            if(maxi == right){
                int len = right-left+1;
                ans.push_back(len);
                left = right+1;
                right++;
                maxi = -1;
            }else{
                right++;
            }
        }
        return ans;
    }
};
