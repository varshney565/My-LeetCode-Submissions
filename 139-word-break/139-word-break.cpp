class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        set<string> Map;
        for(auto x : wordDict){
            Map.insert(x);
        }
        vector<int> dp(n+1,-1);
        function<int(int)> go = [&](int n){
            if(dp[n] != -1) return dp[n];
            if(n == 0) return dp[n] = 1;
            string tmp = "";
            for(int i = n - 1 ; i >= 0 ; i--){
                tmp = s[i] + tmp;
                if(Map.find(tmp) != Map.end()){
                    auto result = go(i);
                    if(result) return dp[n] = result;
                }
            }
            return dp[n] = 0;
        };
        return go(n);
    }
};