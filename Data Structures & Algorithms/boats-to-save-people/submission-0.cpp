class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0;
        int j = people.size()-1;
        int ans = 0;
        while(i <= j){
            if(i == j){
                ans++;
                break;
            }
            int temp = people[i]+people[j];
            if(temp > limit){
                ans++;
                j--;
            }else{
                i++;
                j--;
                ans++;
            }
        }
        return ans;
    }
};