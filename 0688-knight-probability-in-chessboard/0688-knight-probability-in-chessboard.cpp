class Solution {
public:
    double knightProbability(int n, int K, int row, int column) {
        int dir[][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
        double dp[n+1][n+1][K+1];
        memset(dp,0.0,sizeof(dp));
        
        for(int k = 0 ; k <= K ; k++){
            for(int x = 0 ; x < n ; x++){
                for(int y = 0 ; y < n ; y++){
                    if(k == 0) {
                        dp[x][y][k] = 1.0;
                        continue;
                    }
                    for(int i = 0 ; i < 8 ; i++){
                        int newx = x+dir[i][0];
                        int newy = y+dir[i][1];
                        if(newx >= 0 && newx < n && newy >= 0 && newy < n){
                            dp[x][y][k] += dp[newx][newy][k-1];
                        }
                    }
                    dp[x][y][k] /= 8.0;
                }
            }
        }
        return dp[row][column][K];
    }
};