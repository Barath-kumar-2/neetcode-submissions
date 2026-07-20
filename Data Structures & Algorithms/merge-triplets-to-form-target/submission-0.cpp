class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int num1 = -1;
        int num2 = -1;
        int num3 = -1;
        for(int i = 0; i < triplets.size(); i++){
            int curr1 = triplets[i][0];
            int curr2 = triplets[i][1];
            int curr3 = triplets[i][2];
            if(curr1 > target[0] || curr2 > target[1] || curr3 > target[2]){
                continue;
            }
            num1 = max(num1,curr1);
            num2 = max(num2,curr2);
            num3 = max(num3,curr3);
        }
        if(num1 == target[0] && num2 == target[1] && num3 == target[2]){
            return true;
        }
        return false;
    }
};
