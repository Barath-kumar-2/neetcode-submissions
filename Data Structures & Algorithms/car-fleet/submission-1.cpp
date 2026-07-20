class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<double> time(n,0);
        unordered_map<int,double> m;
        for(int i = 0; i < n; i++){
            int pos = position[i];
            int curr = speed[i];
            int dist = target-pos;
            double temp = (double)(dist)/(double)curr;
            m[pos] = temp;
            time[i] = temp;
        }
        sort(position.begin(), position.end());
        for(int i = 0; i < n; i++){
            int it = position[i];
            double curr = m[it];
            time[i] = curr;
        }
        int i = n-1;
        int ans = 0;
        while(i >= 0){
            double temp = time[i];
            int j = i-1;
            while(j >= 0 && time[j] <= temp){
                j--;
            }
            i = j;
            cout << i << endl;
            ans++;
        }
        return ans;

    }
};
