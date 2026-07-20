class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i = 0; i < gas.size(); i++){
            gas[i] -= cost[i];
        }
        int n = gas.size();
        for(int i = 0; i < n; i++){
            gas.push_back(gas[i]);
        }
        int left = 0;
        int right = 0;
        int temp = 0;
        while(left < gas.size() && gas[left] < 0){
            left++;
        }
        right = left;

        while(right < gas.size()){
            temp += gas[right];
            while(temp < 0){
                temp -= gas[left];
                left++;
            }
            int len = right-left+1;
            if(len == n){
                return left;
            }
            right++;
        }   
        return -1;
    }
};
