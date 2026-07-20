class Solution {
public:
    long long minEnd(int n, int x) {
        vector<int> store(64,0);
        int index = 0;
        while(x > 0){
            int temp = (x&1);
            store[index] = temp;
            x >>= 1;
            index++;
        }
        n--;
        for(int i = 0; i < 64; i++){
            if(store[i] == 0){
                store[i] = (n&1);
                n >>= 1; 
            }
        }
        long long ans = 0;
        for(int i = 63; i>= 0; i--){
            int temp = store[i];
            ans |= temp;
            ans <<= 1;
        }
        ans /= 2;
        return ans;
    }
};