class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        priority_queue<pair<int,string>> pq;
        for(auto it : words){
            pq.push({it.size(), it});
        }
        vector<string> arr;
        while(!pq.empty()){
            arr.push_back(pq.top().second);
            pq.pop();
        }
        reverse(arr.begin(), arr.end());
        vector<string> ans;
        for(int i = 0; i < arr.size(); i++){
            string temp = arr[i];
            for(int j = i+1; j < arr.size(); j++){
                string temp2 = arr[j];
                if(temp2.find(temp) != string :: npos){
                    ans.push_back(temp);
                    break;
                }
            }
        }
        return ans;
    }
};
