class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        reverse(digits.begin(), digits.end());
        for(int i = 0; i < digits.size(); i++){
            int num = digits[i];
            int temp = num+carry;
            carry = temp/10;
            int sum = temp%10;
            digits[i] = sum;
        }
        if(carry == 1){
            digits.push_back(1);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
