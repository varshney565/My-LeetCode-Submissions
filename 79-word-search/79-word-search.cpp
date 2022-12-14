class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        function<int(int,int,int)> go = [&](int x,int y,int i){
            if(i == word.size()-1)
                return 1;

            visited[x][y] = true;
            for(int j = 0 ; j < 4 ; j++){
                int newX = x+dir[j][0];
                int newY = y+dir[j][1];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] && word[i+1] == board[newX][newY]){
                    int ans = go(newX,newY,i+1);
                    if(ans) return 1;
                }
            }
            visited[x][y] = false;
            return 0;
        };
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == word[0])
                    if(go(i,j,0))
                        return true;
            }
        }
        return false;
    }
};