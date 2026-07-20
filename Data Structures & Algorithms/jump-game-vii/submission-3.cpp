class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        q.push(0);
        bool ans = false;
        int maxi = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int left = node+minJump;
            int right = node+maxJump;
            left = max(maxi, left);
            for(int i = left; i <= right; i++){
                if(i == s.size()-1 && s[i] == '0'){
                    return true;
                }
                if(i >= s.size()){
                    break;
                }
                if(s[i] == '0'){
                    q.push(i);
                    maxi = i;
                }
            }
        }
        return ans;
    }
};