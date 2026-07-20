class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(1){
            int num = n;
            int temp = 0;
            while(num > 0){
                int digit = num%10;
                num /= 10;
                temp += digit*digit;
            }
            if(temp == 1){
                return true;
            }
            if(s.find(temp) != s.end()){
                return false;
            }
            s.insert(temp);
            n = temp;
        }
        return false;
    }
};
