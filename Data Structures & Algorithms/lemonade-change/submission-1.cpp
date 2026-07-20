class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int t20 = 0;
        for(auto it : bills){
            if(it == 5){
                five++;
            }
            if(it == 10){
                if(five == 0){
                    return false;
                }
                five--;
                ten++;
            }
            if(it == 20){
                t20++;
                if(five >= 1 && ten >= 1){
                    five -= 1;
                    ten -= 1;
                }else if(five >= 3){
                    five -= 3;
                }else{
                    return false;
                }
            }
            if(five < 0 || ten < 0 || t20 < 0){
                return false;
            }
        }
        if(five < 0 || ten < 0 || t20 < 0){
            return false;
        }
            return true;
    }
};