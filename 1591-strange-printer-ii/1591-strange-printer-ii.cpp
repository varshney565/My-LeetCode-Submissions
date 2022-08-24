class Solution {
public:
    bool isPrintable(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //Helping To calculate the boundries of each colour
        vector<vector<int>> Colour(61,vector<int>{INT_MAX,INT_MIN,INT_MAX,INT_MIN});
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                Colour[grid[i][j]][0] = min(Colour[grid[i][j]][0],i);
                Colour[grid[i][j]][1] = max(Colour[grid[i][j]][1],i);
                Colour[grid[i][j]][2] = min(Colour[grid[i][j]][2],j);
                Colour[grid[i][j]][3] = max(Colour[grid[i][j]][3],j);
            }
        }
        
        //which color has done its work means it's dependecy is clear now.
        vector<int> visited(61,false);
        int cnt = 100;
        //cnt is storing whether we have any other dependencies remaining or not
        //if cnt is zero means we can't uncolour from this point so we have to break
        while(cnt){
            cnt = 0;
            for(int i = 0 ; i <= 60 ; ++i){
                if(visited[i]) continue;
                if(Colour[i][0] == INT_MAX) continue;
                //checking how many colour in this range x1,x2,y1,y2
                //if only one colour unpaint it
                //and clear its dependency
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
                //if there is no colour means already unpainted 
                //no need to increament the count.
                if(Container.size() == 0){
                    visited[i] = true;
                    ok = false;
                }
                //if we are clearing any dependency we will mark all elements as 0
                //ans increament the count
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
        //checking whether whole grid is unpainted or not if yes return true 
        //else return fasle
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