class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int val = 1,left = 0,right = n-1,up = 0,down = n-1;
        while(up <= down && left <= right){
            for(int i = left ; i <= right ; i++){
                ans[up][i] = val++;
            }
            up++;
            for(int i = up ; i <= down ; i++){
                ans[i][right] = val++;
            }
            right--;
            if(left > right || up > down) break;
            for(int i = right ; i >= left ; i--){
                ans[down][i] = val++;
            }
            down--;
            for(int i = down ; i >= up ; i--){
                ans[i][left] = val++;
            }
            left++;
        }
        return ans;
    }
};