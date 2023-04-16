class Solution {
public:
    int dig(int n){
        if(n < 10) return 1;
        return 1 + dig(n/10);
    }

    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans(m,0);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                int p = (grid[i][j] >= 0 ? 0 : 1);
                ans[j] = max(ans[j],dig(abs(grid[i][j])) + p);
            }
        }
        return ans;
    }
};