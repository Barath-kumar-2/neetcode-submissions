class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int temp = k;
        for(int i = 0; i < 26; i++){
            char ch = 'A'+i;
            int left = 0;
            int right = 0;
            k = temp;
            while(right < s.size()){
                if(s[right] != ch){
                    if(k > 0){
                        k--;
                    }else{
                        k--;
                        while(k <= 0){
                            if(s[left] != ch){
                                k++;
                            }
                            left++;
                            if(k == 0){
                                break;
                            }
                        }
                        
                    }
                }
                cout << ch << "," << right << left << k << endl;
                ans = max(ans, right-left+1);
                right++;
            }
        }
        return ans;
    }
};
