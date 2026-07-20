class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int start = 0;
        while(start < arr.size()-1 && arr[start] == arr[start+1]){
            start++;
        }
        if(start == arr.size()-1){
            return 1;
        }
        int flag = 0;
        if(arr[start] < arr[start+1]){
            flag = 1;
        }
        int ans = 2;
        int left = start;
        int right = start+1;
        while(right < arr.size()-1){
            if(arr[right+1] > arr[right] && (flag == 0)){
                flag = 1;
                right++;
            }else if(arr[right+1] < arr[right] && (flag == 1)){
                right++;
                flag = 0;
            }
            else if(arr[right] < arr[right+1]){
                left = right;
                right++;
                flag = 1;
            }
            else if(arr[right] > arr[right+1]){
                left = right;
                right++;
                flag = 0;
            }else{
                while(right < arr.size()-1 && arr[right] == arr[right+1]){
                    right++;
                }
                left = right;
                flag = 0;
                if(arr[right] < arr[right+1]){
                    flag = 1;
                }
                right = right+1;
            }
            int len = right-left+1;
            ans = max(ans, len);
        }
        return ans;
    }
};