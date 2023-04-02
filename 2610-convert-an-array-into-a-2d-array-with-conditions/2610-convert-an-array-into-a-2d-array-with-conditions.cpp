class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        map<int,int> cnt;
        for(auto x : nums){
            cnt[x]++;
        }
        while(cnt.size() > 0 ){
            vector<int> t;
            for(auto &x : cnt){
                t.push_back(x.first);
                x.second--;
            }
            for(auto x : t){
                if(cnt[x] == 0){
                    cnt.erase(x);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};