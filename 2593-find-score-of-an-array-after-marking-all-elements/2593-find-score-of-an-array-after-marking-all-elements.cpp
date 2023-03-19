
class Solution {
public:
    long long findScore(vector<int>& nums) {
        set<pair<int,int>> m;
        int n = nums.size();
        for(int i = 0 ; i < nums.size() ; i++){
            m.insert({nums[i],i});
        }
        vector<bool> visited(n,false);
        long long ans = 0;
        while(!m.empty()){
            auto small = *m.begin();
            int ind = small.second;
            long long val = small.first;
            if(!visited[ind]){
                ans += val;
                visited[ind] = true;
                if(ind-1 >= 0){
                    visited[ind-1] = true;
                }
                if(ind + 1 < n){
                    visited[ind+1] = true;
                }
            }else{
                m.erase(m.begin());
            }
        }
        return ans;
    }
};
