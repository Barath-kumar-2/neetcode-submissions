class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int srow = 0;
        int erow = matrix.size()-1;
        int scol = 0;
        int ecol = matrix[0].size()-1;
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int size= n *m;
        int i = 0;
        while(ans.size() < size){
            while(i <= ecol){
                ans.push_back(matrix[srow][i]);
                i++;
            }
            srow++;
            i = srow;
            if(ans.size() == size){
                break;
            }
            while(i <= erow){
                ans.push_back(matrix[i][ecol]);
                i++;
            }
            if(ans.size() == size){
                break;
            }
            ecol--;
            i = ecol;
            while(i >= scol){
                ans.push_back(matrix[erow][i]);
                i--;
            }
            if(ans.size() == size){
                break;
            }
            erow--;
            i = erow;
            while(i >= srow){
                ans.push_back(matrix[i][scol]);
                i--;
            }
            if(ans.size() == size){
                break;
            }
            scol++;
            i = scol;
            cout << ans.size() << endl;
        }
        return ans;
    }
};
