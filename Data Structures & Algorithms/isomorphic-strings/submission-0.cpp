class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char,char> m1;
        unordered_map<char,char> m2;
        
        for(int i = 0; i < s.size(); i++){
            char it = s[i];
            if(m1.find(it) != m1.end()){
                char ch = t[i];
                if(m2.find(ch) == m2.end() || m2[ch] != it){
                    return false;
                }
            }
            char ele = t[i];
            if(m2.find(ele) != m2.end()){
                char ch = s[i];
                if(m1.find(ch) == m1.end() || m1[ch] != ele){
                    return false;
                }
            }
            m1[it] = ele;
            m2[ele] = it;
        }
        return true;
    }
};