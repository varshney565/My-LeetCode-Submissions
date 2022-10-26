class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        vector<vector<pair<int,int>>> tempAns;
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = 0 ; j < nums[i].size() ; j++){
                //diagonal number ----> i+j
                if(tempAns.size() == i+j)
                    tempAns.push_back({});
                tempAns[i+j].push_back({j,nums[i][j]});
            }
        }
        for(int i = 0 ; i < tempAns.size() ; i++)
            sort(tempAns[i].begin(),tempAns[i].end());
        for(int i = 0 ; i < tempAns.size() ; i++){
            for(int j = 0 ; j < tempAns[i].size() ; j++){
                ans.push_back(tempAns[i][j].second);
            }
        }
        return ans;
    }
};