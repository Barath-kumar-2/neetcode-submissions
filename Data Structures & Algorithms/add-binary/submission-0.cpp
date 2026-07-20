class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int carry = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i = 0;
        int j = 0;
        while(i < a.size() && j < b.size()){
            int num1 = a[i]-'0';
            int num2 = b[j]-'0';
            int temp = num1+num2+carry;
            int sum = temp%2;
            carry = temp/2;
            ans += sum+'0';
            i++;
            j++;
        }
        while(i < a.size()){
            int num1 = a[i]-'0';
            int num2 = 0;
            int temp = num1+num2+carry;
            int sum = temp%2;
            carry = temp/2;
            ans += sum+'0';
            i++;
        }
        while(j < b.size()){
            int num1 = 0;
            int num2 = b[j]-'0';
            int temp = num1+num2+carry;
            int sum = temp%2;
            carry = temp/2;
            ans += sum+'0';
            j++;
        }
        if(carry == 1){
            ans += '1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};