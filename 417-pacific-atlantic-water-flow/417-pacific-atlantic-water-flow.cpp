class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> ToAtlantic(n,vector<bool>(m,false));
        vector<vector<bool>> ToPacific(n,vector<bool>(m,false));
        int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};        
        
        function<void(int,int,vector<vector<bool>>&)> go = [&](int x,int y,vector<vector<bool>> &visited){
            visited[x][y] = true;
            for(int i = 0 ; i < 4 ; i++){
                int newX = x+dir[i][0];
                int newY = y+dir[i][1];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] && heights[newX][newY] >= heights[x][y]){
                     go(newX,newY,visited);
                }
            }
        };
        
        for(int i = 0 ; i < n ; i++){
            if(!ToAtlantic[i][m-1])
                go(i,m-1,ToAtlantic);
            if(!ToPacific[i][0])
                go(i,0,ToPacific);
        }
        
        for(int j = 0 ; j < m ; j++){
            if(!ToAtlantic[n-1][j])
                go(n-1,j,ToAtlantic);
            if(!ToPacific[0][j])
                go(0,j,ToPacific);
        }
        
        vector<vector<int>> ans;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(ToAtlantic[i][j] && ToPacific[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};