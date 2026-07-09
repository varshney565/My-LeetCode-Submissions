class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
        //wsf,x,y
        pq.push({0,0,0});
        distance[0][0] = 0;
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int cost_so_far = top[0];
            int x = top[1];
            int y = top[2];
            // cout<<x<<" : "<<y<<"\n";
            if(distance[x][y] < cost_so_far) continue;
            if(x == n - 1 && y == m - 1) {
                return cost_so_far;
            }
            for(auto d : dir) {
                int newx = x + d[0];
                int newy = y + d[1];
                if(newx >= 0 && newx < n && newy >= 0 && newy < m) {
                    int cost = cost_so_far;
                    if(grid[newx][newy] == 1) {
                        cost++;
                    }
                    if(cost < distance[newx][newy]) {
                        distance[newx][newy] = cost;
                        pq.push({cost,newx,newy});
                    }
                }
            }
        }
        return -1;
    }
};