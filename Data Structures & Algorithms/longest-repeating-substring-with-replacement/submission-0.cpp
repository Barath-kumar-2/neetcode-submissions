class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> m;
        map<int,unordered_set<int>> m2;
        int ans = 0;
        int left = 0;
        int right = 0;
        
        while(right < s.size()){
            if(m.find(s[right]) != m.end()){
                int old = m[s[right]];
                m2[old].erase(s[right]);
                if(m2[old].empty()){
                    m2.erase(old);
                }
                m[s[right]]++;
                int temp = m[s[right]];
                m2[temp].insert(s[right]);
            }else{
                m[s[right]]++;
                int temp = m[s[right]];
                m2[temp].insert(s[right]);
            }
            int curr = right-left+1;
            int maxi = m2.rbegin()->first;
            int dif = curr-maxi;
            cout << dif << endl;
            while(dif > k){
                int old = m[s[left]];
                m[s[left]]--;
                if(m[s[left]] == 0){
                    m.erase(s[left]);
                }
                int upd = m[s[left]];
                m2[upd].insert(s[left]);
                m2[old].erase(s[left]);
                if(m2[old].empty()){
                    m2.erase(old);
                }
                left++;
                curr = right-left+1;
                maxi = m2.rbegin()->first;
                dif = maxi-curr;
            }
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};
