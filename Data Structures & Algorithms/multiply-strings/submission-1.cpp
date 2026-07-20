class Solution {
public:
    string solve(string num1, char ch){
        int carry = 0;
        string s = "";
        for(int i = 0; i < num1.size(); i++){
            int t1 = num1[i]-'0';
            int t2 = ch-'0';
            int t3 = t1*t2+carry;
            carry = t3/10;
            t3 %= 10;
            s += t3+'0';
        }
        if(carry != 0){
            s += carry+'0';
        }
        return s;
    }
    string add(string temp1, string temp2){
        reverse(temp1.begin(), temp1.end());
        reverse(temp2.begin(), temp2.end());
        int carry = 0;
        int i = 0;
        int j = 0;
        string s = "";
        while((i < temp1.size()) || (j < temp2.size()) || (carry != 0)){
            int num1 = 0;
            int num2 = 0;
            if(i < temp1.size()){
                num1 = temp1[i]-'0';
            }
            if(j < temp2.size()){
                num2 = temp2[j]-'0';
            }
            int sum = (num1+num2+carry)%10;
            s += sum +'0';
            carry = (num1+num2+carry)/10;
            i++;
            j++;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    string multiply(string num1, string num2) {
        vector<string> ans;
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        reverse(num2.begin(), num2.end());
        reverse(num1.begin(), num1.end());
        string temp = "";
        for(int i = 0; i < num2.size(); i++){
            if(i != 0){
                temp += '0';
            }
            string res = temp;
            char ch = num2[i];
            res += solve(num1,ch);
            reverse(res.begin(), res.end());
            //return res;
            ans.push_back(res);
        }
        string op = ans[0];
        for(int i = 1; i < ans.size(); i++){
            string curr = add(op, ans[i]);
            op = curr;
        }
        return op;
    }
};
