class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;
        int temp =right;
        while(temp > 0){
            count++;
            temp = temp>>1;
        }
        int num2 = right;
        int num1 = 1 << (count-1);
        if(num1 > left){
            return 0;
        }
        num1 = max(left,num1);
        vector<int> store1(32,0);
        vector<int> store2(32,0);
        int index = 0;
        
        while(num1 > 0 || num2 > 0){
            store1[index] = (num1&1);
            store2[index] = (num2&1);
            num1 >>=1;
            num2 >>=1;
            index++;
        } 
        
        int ans = 0;
        for(int i = 31; i>=0;i--){
            if(store1[i] == store2[i]){
                int temp = store1[i];
                cout << temp << endl;
                ans <<= 1;
                ans |= temp;
            }else{
                ans <<= (i+1);
                break;
            }
        }
        return ans;
    }
};