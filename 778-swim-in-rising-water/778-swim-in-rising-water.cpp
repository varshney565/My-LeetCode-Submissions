class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int ans = INT_MIN;
        int n = grid.size();
        int m = grid[0].size();
        set<pair<int,int>> PendingNodes;
        PendingNodes.insert({grid[0][0],0});
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!PendingNodes.empty()){
            pair<int,int> front = *PendingNodes.begin();
            PendingNodes.erase(front);
            int x = front.second/m;
            int y = front.second%m;
            int cost = front.first;
            if(grid[x][y] == -1){
                continue;
            }
            ans = max(ans,cost);
            if(x == n-1 && y == m-1){
                return ans;
            }
            grid[x][y] = -1;
            for(int i = 0 ; i < 4 ; i++){
                int newX = x+dir[i][0];
                int newY = y+dir[i][1];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] != -1){
                    PendingNodes.insert({grid[newX][newY],newX*m+newY});
                }
            }
        }
        return -1;
    }
};