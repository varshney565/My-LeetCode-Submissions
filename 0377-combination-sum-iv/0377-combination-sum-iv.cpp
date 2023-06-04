class Solution {
public:
    int combinationSum4(vector<int>& v, int T) {
        int n = v.size();
        vector<int> dp(T+1,-1);
        function<int(int)> go = [&](int sum){
            if(sum == 0) return dp[sum] = 1;
            if(dp[sum] != -1) return dp[sum];
            int ans = 0;
            for(int i = 0 ; i < n ; i++){
                if(sum-v[i] >= 0)
                    ans += go(sum-v[i]);
            }
            return dp[sum] = ans;
        };
        return go(T);
    }
};