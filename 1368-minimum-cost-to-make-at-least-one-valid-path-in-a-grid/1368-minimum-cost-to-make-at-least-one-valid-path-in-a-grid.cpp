class Solution {
public:
    //1 right
    //2 left
    //3 lower
    //4 up
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> Cost(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> PendingCells;
        PendingCells.push({0,0});
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!PendingCells.empty()){
            pair<int,int> front = PendingCells.front();
            PendingCells.pop();
            int cost = front.first;
            int x = front.second/m;
            int y = front.second%m;
            if(Cost[x][y] <= cost){
                continue;
            }
            Cost[x][y] = cost;
            for(int i = 1 ; i <= 4 ; i++){
                int newX = x+dir[i-1][0];
                int newY = y+dir[i-1][1];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m){
                    if(grid[x][y] == i){
                        PendingCells.push({cost,newX*m+newY});
                    }else{
                        PendingCells.push({cost+1,newX*m+newY});
                    }
                }
            }
        }
        return Cost[n-1][m-1];
    }
};