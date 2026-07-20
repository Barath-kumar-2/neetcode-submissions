class Solution {
public:
    int solve(int num1, int num2){
        int a = max(num1,num2);
        int b = min(num1,num2);
        while(b!= 0){
            int temp = b;
            b = a%b;
            a=temp;
        }
        return a;
    }
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.size();
        int len2 = str2.size();
        if(str1+str2 != str2+str1){
            return "";
        }
        int ans = solve(len1,len2);
        string res = "";
        for(int i = 0; i < ans; i++){
            res += str1[i];
        }
        return res;
        
    }
};