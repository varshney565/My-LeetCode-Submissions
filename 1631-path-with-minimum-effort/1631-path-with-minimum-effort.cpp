class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        set<pair<int,int>> PendingCells;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        PendingCells.insert({0,0});
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!PendingCells.empty()){
            auto front = *PendingCells.begin();
            PendingCells.erase(front);
            int cost = front.first;
            int x = front.second/m;
            int y = front.second%m;
            if(visited[x][y]){
                continue;
            }
            visited[x][y] = true;
            if(x == n-1 && y == m-1){
                return cost;
            }
            for(int i = 0 ; i < 4 ; i++){
                int newX = x+dir[i][0];
                int newY = y+dir[i][1];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY]){
                    int newCost = abs(heights[x][y]-heights[newX][newY]);
                    PendingCells.insert({max(cost,newCost),newX*m+newY});
                }
            }
        }
        return -1;
    }
};