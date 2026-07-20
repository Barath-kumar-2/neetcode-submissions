class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> store(26,0);
        int val = 0;
        for(auto it : order){
            int num = it-'a';
            store[num] = val;
            val++;
        }
        for(int i = 0; i < words.size()-1; i++){
            string temp1 = words[i];
            string temp2 = words[i+1];
            int size1 = temp1.size();
            int size2 = temp2.size();
            int len = min(size1, size2);
            int flag = 1;
            for(int j = 0; j < len; j++){
                int w1 = temp1[j]-'a';
                int w2 = temp2[j]-'a';
                if(store[w2] > store[w1]){
                    flag = 0;
                    break;
                }
                if(store[w1] > store[w2]){
                    cout << i << endl;
                    return false;
                }
                if(w1 != w2){
                    flag = 0;
                }
            }
            if((flag == 1) && (size1 > size2)){
                return false;
            }
        }
        return true;
    }
};