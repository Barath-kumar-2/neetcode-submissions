class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        bool sign = true;
        if(x < 0){
            sign = false;
        }
        x = abs(x);
        while(x > 0){
            int curr = x%10;
            x /= 10;
            if(ans >= (INT_MAX/10)-curr){
                return 0;
            }
            ans *= 10;
            ans += curr;
        }
        if(!sign){
            return -1*ans;
        }
        return ans;
    }
};
