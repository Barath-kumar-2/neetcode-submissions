class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> m;
        for(auto it : hand){
            m[it]++;
        }
        int count = hand.size()/groupSize;
        if(hand.size()%groupSize != 0){
            return false;
        }
        while(count > 0){
            int temp = groupSize;
            int mini = m.begin()->first;
            cout << mini << endl;
            while(temp > 0){
                if(m.find(mini) == m.end()){
                    return false;
                }
                m[mini]--;
                if(m[mini] == 0){
                    m.erase(mini);
                }
                temp--;
                mini++;
            }
            count--;
        }
        return true;
    }
};
