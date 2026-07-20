class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        queue<int> q;
        q.push(0);
        int maxi = 0;
        while(!q.empty()){
            int node = q.front();
            
            if(node >= n-1){
                return true;
            }
            int l = node + minJump;
            int temp2 = node+maxJump;
            int temp = n-1;
            int r = min(temp2, temp);
            maxi = max(maxi, l);
            q.pop();
            cout << temp << endl;
            for(int i = maxi; i <= r; i++){
                if(s[i] == '0'){
                    q.push(i);
                    maxi = i;
                    
                }
            }
        }
        return false;
    }
};