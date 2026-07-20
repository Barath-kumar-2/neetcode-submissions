class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t a = 0;
        int count = 32;
        while(count > 0){
            int temp = n&1;
            a <<= 1;
            a = (a| temp);
            n >>= 1;
            count--;
        }
        return a;
    }
};
