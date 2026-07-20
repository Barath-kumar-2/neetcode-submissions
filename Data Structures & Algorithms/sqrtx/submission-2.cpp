class Solution {
public:
    int mySqrt(int x) {
        if(x == 0){
            return 0;
        }
        int start = 1; 
        int end = x;
        while(start <= end){
            long long mid = start +(end-start)/2;
            long long curr = mid*mid;
            if(curr == x){
                return mid;
            }else if(curr < x){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return end;
    }
};