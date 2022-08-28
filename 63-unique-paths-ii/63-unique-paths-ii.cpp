class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        int dir[2][2] = {{-1,0},{0,-1}};
        vector<vector<int>> dp(n,vector<int>(m,-1));
        function<int(int,int)> go = [&](int x,int y){
            if(g[x][y] == 1)
                return 0;
            if(x == 0 && y == 0)
                return 1;
            if(dp[x][y] != -1) return dp[x][y];
            int ans = 0;
            for(int i = 0 ; i < 2 ; i++){
                int newX = x+dir[i][0];
                int newY = y+dir[i][1];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m){
                    ans += go(newX,newY);
                }
            }
            return dp[x][y] = ans;
        };
        return go(n-1,m-1);
    }
};