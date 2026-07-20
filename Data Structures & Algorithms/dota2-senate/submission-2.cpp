class Solution {
public:
    string predictPartyVictory(string senate) {
        unordered_set<int> s;
        int count = 0;
        int rcount = 0;
        int ccount = 0;
        for(auto it : senate){
            if(it == 'R'){
                rcount++;
            }else{
                ccount++;
            }
        }
        if(rcount == 0){
            return "Dire";
        }
        if(ccount == 0){
            return "Radiant";
        }
        while(s.size() < senate.size()-1){
            for(int i = 0; i < senate.size(); i++){
                if(s.find(i) != s.end()){
                    continue;
                }
                if(senate[i] =='R'){
                    if(count < 0){
                        count++;
                        rcount--;
                        s.insert(i);
                    }else{
                        count++;
                    }
                }else{
                    if(count > 0){
                        count--;
                        ccount--;
                        s.insert(i);
                    }else{
                        count--;
                    }
                }
                if(s.size() == senate.size()-1){
                    break;
                }
                if(rcount == 0){
                    return "Dire";
                }
                if(ccount == 0){
                    return "Radiant";
                }
            }
        }  
        for(int i = 0; i < senate.size(); i++){
            if(s.find(i) == s.end()){
                if(senate[i] == 'R'){
                    return "Radiant";
                }
            }
        }
        return "Dire";
    }
};