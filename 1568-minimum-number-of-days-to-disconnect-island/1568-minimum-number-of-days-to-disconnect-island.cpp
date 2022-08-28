class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        //if the graph has already greater than 1 components than ans is 0
        //if the graph has any articulation point than ans is 1
        //else ans is 2
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> disc(n,vector<int>(m,0));
        vector<vector<int>> low(n,vector<int>(m,0));
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        bool ok = false;
        function<void(int,int,int&,int)> dfs = [&](int x,int y,int &time,int p){
            visited[x][y] = true;
            disc[x][y] = low[x][y] = time++;
            int rootCall = 0;
            for(int i = 0 ; i < 4 ; i++){
                int newX = x+dir[i][0];
                int newY = y+dir[i][1];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1 && newX*m+newY != p){
                    if(!visited[newX][newY]){
                        dfs(newX,newY,time,x*m+y);
                        low[x][y] = min(low[x][y],low[newX][newY]);
                        if(p == -1){
                            rootCall++;
                        }else if(disc[x][y] <= low[newX][newY]){
                            ok = true;
                        }
                    }else{
                        low[x][y] = min(low[x][y],disc[newX][newY]);
                    }
                }
            }
            if(p == -1 && rootCall > 1){
                ok = true;
            }
        };
        int to1 = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    to1++;
                    if(!visited[i][j]){
                        int time = 1;
                        dfs(i,j,time,-1);
                        count++;
                    }
                }
            }
        }
        if(count > 1){
            return 0;
        }else if(ok){
            return 1;
        }else{
            if(to1 == 1){
                return 1;
            }else if(to1 == 0){
                return 0;
            }
            return 2;
        }
    }
};