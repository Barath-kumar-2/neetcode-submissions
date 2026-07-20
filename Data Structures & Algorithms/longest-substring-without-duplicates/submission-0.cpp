class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int ans = 0;
        int left = 0;
        int right = 0;
        while(right < s.size()){
            char ch = s[right];
            while(m.find(ch) != m.end()){
                m[s[left]]--;
                if(m[s[left]] == 0){
                    m.erase(s[left]);
                }
                left++;
            }
            m[s[right]]++;
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};
