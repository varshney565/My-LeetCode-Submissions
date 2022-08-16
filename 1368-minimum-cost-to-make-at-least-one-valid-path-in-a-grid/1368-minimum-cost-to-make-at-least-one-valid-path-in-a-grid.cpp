class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> Cost(n,vector<int>(m,INT_MAX));
        set<pair<int,int>> PendingCells;
        PendingCells.insert({0,0});
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!PendingCells.empty()){
            pair<int,int> front = *PendingCells.begin();
            PendingCells.erase(front);
            int cost = front.first;
            int x = front.second/m;
            int y = front.second%m;
            if(x == n-1 && y == m-1) return cost;
            if(Cost[x][y] <= cost){
                continue;
            }
            Cost[x][y] = cost;
            for(int i = 1 ; i <= 4 ; i++){
                int newX = x+dir[i-1][0];
                int newY = y+dir[i-1][1];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m){
                    if(grid[x][y] == i){
                        PendingCells.insert({cost,newX*m+newY});
                    }else{
                        PendingCells.insert({cost+1,newX*m+newY});
                    }
                }
            }
        }
        return Cost[n-1][m-1];
    }
};