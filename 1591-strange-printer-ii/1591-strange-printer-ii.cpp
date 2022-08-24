class Solution {
public:
    bool isPrintable(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> Colour(61,vector<int>{INT_MAX,INT_MIN,INT_MAX,INT_MIN});
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                Colour[grid[i][j]][0] = min(Colour[grid[i][j]][0],i);
                Colour[grid[i][j]][1] = max(Colour[grid[i][j]][1],i);
                Colour[grid[i][j]][2] = min(Colour[grid[i][j]][2],j);
                Colour[grid[i][j]][3] = max(Colour[grid[i][j]][3],j);
            }
        }
        
        vector<int> visited(61,false);
        int cnt = 100;
        while(cnt){
            cnt = 0;
            for(int i = 0 ; i <= 60 ; ++i){
                if(visited[i]) continue;
                if(Colour[i][0] == INT_MAX) continue;
                int x1 = Colour[i][0],x2 = Colour[i][1],y1 = Colour[i][2],y2 = Colour[i][3];
                set<int> Container;
                bool ok = true;
                for(int r = x1 ; r <= x2 ; r++){
                    for(int c = y1 ; c <= y2 ; c++){
                        if(grid[r][c]){
                            Container.insert(grid[r][c]);
                        }
                        if(Container.size() > 1){
                            ok = false;
                            break;
                        }
                    }
                    if(!ok)
                        break;
                }
                if(Container.size() == 0){
                    visited[i] = true;
                    ok = false;
                }
                if(ok){
                    for(int r = x1 ; r <= x2 ; r++){
                        for(int c = y1 ; c <= y2 ; c++){
                            grid[r][c] = 0;
                        }
                    }
                    visited[i] = true;
                    cnt++;
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
};