class Solution {
public:

    string encode(vector<string>& strs) {
        string temp = "";
        for(auto it : strs){
            
            for(auto ch : it){
                temp += ch;
            }
            temp += '.';
        }
        return temp;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        cout << s << endl;
        string temp = "";
        for(auto it : s){
            if(it == '.'){
                ans.push_back(temp);
                temp = "";
            }else{
                temp += it;
            }
        }
        return ans;
    }
};
