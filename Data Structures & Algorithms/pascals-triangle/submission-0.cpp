class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i < numRows; i++){
            vector<int> temp;
            for(int j = 0; j <= i; j++){
                if(j == 0){
                    temp.push_back(1);
                }else if(j == i){
                    temp.push_back(1);
                }else{
                    //cout << ans.size() << "," << i << "," << ans[i-1].size() << "," << j << endl;
                    int curr = ans[i-1][j-1] + ans[i-1][j];
                    temp.push_back(curr);
                }
            }
           
            ans.push_back(temp);
        }
        return ans;
    }
};
