class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> depend(n,vector<int>(m,0));
        int dir[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
        queue<int> PendingCell;
        int level = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                for(int k = 0 ; k < 4 ; k++){
                    int newi = i+dir[k][0];
                    int newj = j+dir[k][1];
                    if(newi >= 0 && newi < n && newj >= 0 && newj < m && matrix[newi][newj] < matrix[i][j]){
                        depend[i][j]++;
                    }
                }
                if(depend[i][j] == 0){
                    PendingCell.push(i*m+j);
                }
            }
        }
        while(!PendingCell.empty()){
            int size = PendingCell.size();
            while(size-->0){
                int front = PendingCell.front();
                PendingCell.pop();
                int x = front/m;
                int y = front%m;
                for(int i = 0 ; i < 4 ; i++){
                    int newx = x+dir[i][0];
                    int newy = y+dir[i][1];
                    if(newx >= 0 && newx < n && newy >= 0 && newy < m && matrix[newx][newy] > matrix[x][y]){
                        depend[newx][newy]--;
                        if(depend[newx][newy] == 0) PendingCell.push(newx*m+newy);
                    }
                }
            }
            level++;
        }
        return level;
    }
};