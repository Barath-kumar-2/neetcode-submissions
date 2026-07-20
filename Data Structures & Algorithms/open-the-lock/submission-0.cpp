class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        string start = "0000";
        pq.push({0,start});
        unordered_set<string> s;
        unordered_set<string> v;
        for(auto it : deadends){
            s.insert(it);
        }
        while(!pq.empty()){
            int index = pq.top().first;
            string temp = pq.top().second;
            pq.pop();
            if(s.find(temp) != s.end()){
                continue;
            }
            cout << temp << "," << index << endl;
            if(temp == target){
                return index;
            }
            for(int i = 0; i < 4; i++){
                char ch = temp[i];
                if(temp[i] == '9'){
                    temp[i] = '0';
                    if(v.find(temp) == v.end()){
                        pq.push({index+1,temp});
                        v.insert(temp);
                    }
                    temp[i] = '8';
                    if(v.find(temp) == v.end()){
                       pq.push({index+1,temp});
                        v.insert(temp);
                    }
                }else if(temp[i] == '0'){
                    temp[i] = '9';
                    if(v.find(temp) == v.end()){
                        pq.push({index+1,temp});
                        v.insert(temp);
                    }
                    temp[i] = '1';
                    if(v.find(temp) == v.end()){
                        pq.push({index+1,temp});
                        v.insert(temp);
                    }
                }else{
                    char store = temp[i];
                    temp[i] = store+1;
                    if(v.find(temp) == v.end()){
                        pq.push({index+1,temp});
                        v.insert(temp);
                    }
                    temp[i] = store-1;
                    if(v.find(temp) == v.end()){
                        pq.push({index+1,temp});
                        v.insert(temp);
                    }
                }
                temp[i] = ch;
                
            }
        }
        return -1;
    }
};