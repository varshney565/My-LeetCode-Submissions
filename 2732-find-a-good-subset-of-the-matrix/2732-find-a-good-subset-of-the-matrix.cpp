class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>> numbers;
        set<int> store;
        for(int i = 0 ; i < n ; i++){
            int val = 0;
            for(int j = 0 ; j < m ; j++){
                val = (val | (grid[i][j]));
                if(j < m - 1)
                    val = val<<1;
            }
            if(val == 0) return {i};
            if(store.find(val) != store.end()) continue;
            store.insert(val);
            numbers.push_back({i,val});
        }
        for(int i = 0 ; i < numbers.size() ; i++){
            for(int j = i + 1 ; j < numbers.size() ; j++){
                int t = (numbers[i].second & numbers[j].second);
                if(t) continue;
                return {numbers[i].first,numbers[j].first};
            }
        }
        return {};
    }
};