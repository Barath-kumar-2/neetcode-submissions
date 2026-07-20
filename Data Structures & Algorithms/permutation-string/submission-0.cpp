class Solution {
public:
    bool check(vector<int> freq1, vector<int> freq2){
        for(int i = 0; i < 26; i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int>freq1(26,0);
        if(s2.size() < s1.size()){
            return false;
        }
        for(int i = 0; i < s1.size(); i++){
            int temp = s1[i]-'a';
            freq1[temp]++;
        }
        int len = s1.size();
        vector<int> freq2(26,0);
        for(int i = 0; i < len; i++){
            int temp = s2[i]-'a';
            freq2[temp]++;
        }
        
        int left = 0;
        int right = len-1;
        while(right < s2.size()){
            if(check(freq1, freq2)){
                return true;
            }
            int temp = s2[left]-'a';
            freq2[temp]--;
            right++;
            left++;
            if(right == s2.size()){
                break;
            }
            temp = s2[right]-'a';
            freq2[temp]++;
        }
        return false;
    }
};
