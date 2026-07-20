class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> nge(n,0);
        vector<int> pge(n,0);
        pge[0] = height[0];
        nge[n-1] = height[n-1];
        // find pge
        int maxi = height[0];
        for(int i = 1; i < n; i++){
            maxi = max(maxi, height[i]);
            pge[i] = maxi;
        }
        maxi = height[n-1];
        // find nge
        for(int i = n-2; i >= 0; i--){
            maxi = max(maxi, height[i]);
            nge[i] = maxi;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int temp = min(pge[i], nge[i]);
            int curr = temp-height[i];
            ans += (curr > 0 ? curr : 0);
        }
        return ans;
    }
};
