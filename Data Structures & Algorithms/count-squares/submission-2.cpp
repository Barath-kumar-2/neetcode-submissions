class CountSquares {
public:
    struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
    };
    unordered_map<pair<int,int>, int, pair_hash> m;
    vector<vector<int>> v;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int num1 = point[0];
        int num2 = point[1];
        m[{num1,num2}]++;
        v.push_back(point);
    }
    
    int count(vector<int> point) {
        int num1 = point[0];
        int num2 = point[1];
        int ans = 0;
        for(int i = 0; i < v.size(); i++){
            int temp = v[i][0];
            int temp2 = v[i][1];
            int dif1 = abs(temp-num1);
            int dif2 = abs(temp2-num2);
            if(dif1 == 0 && dif2 == 0){
                continue;
            }
            if(dif1 == dif2){
                int count1 = 1;
                int count2 = m[{num1, temp2}];
                int count3 = m[{temp, num2}];
                ans += (count1*count2*count3);
            }
        }
        return ans;
    }
};
