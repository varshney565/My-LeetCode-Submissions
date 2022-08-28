class Solution {
public:
    int uniquePaths(int m, int n) {
        int dir[2][2] = {{-1,0},{0,-1}};
        vector<vector<int>> dp(m,vector<int>(n,-1));
        function<int(int,int)> go = [&](int x,int y){
            if(x == 0 || y == 0)
                return 1;
            if(dp[x][y] != -1) return dp[x][y];
            int ans = 0;
            for(int i = 0 ; i < 2 ; i++){
                int newX = x+dir[i][0];
                int newY = y+dir[i][1];
                if(newX >= 0 && newX < m && newY >= 0 && newY < n){
                    ans += go(newX,newY);
                }
            }
            return dp[x][y] = ans;
        };
        return go(m-1,n-1);
    }
};