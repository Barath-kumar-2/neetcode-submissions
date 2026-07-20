class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }
        if(n < 0){
            x = 1.0/x;
            n = abs(n);
        }
        double half = 0;
        if(n%2 == 0){
            n /= 2;
            half = myPow(x, n);
            half *= half;
        }else{
            n /= 2;
            half = myPow(x, n);
            half *= half;
            half *= x;
        }
        return half;
    }
};
