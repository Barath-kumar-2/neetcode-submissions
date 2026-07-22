class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(int i = 0; i < details.size(); i++){
            int age = 0;
            char ch1 = details[i][11];
            char ch2 = details[i][12];
            age += (ch1-'0');
            age *= 10;
            age += (ch2-'0');
            if(age > 60){
                count++;
            }
        }
        return count;
    }
};