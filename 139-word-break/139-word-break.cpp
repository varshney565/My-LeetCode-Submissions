class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        set<string> Map;
        for(auto x : wordDict){
            Map.insert(x);
        }
        vector<int> dp(n+1,-1);
        function<int(int)> go = [&](int start){
            if(start == n) return dp[start] = 1;
            if(dp[start] != -1) return dp[start];
            string tmp = "";
            for(int i = start ; i < n ; i++){
                tmp += s[i];
                if(Map.find(tmp) != Map.end()){
                    auto result = go(i+1);
                    if(result) return dp[start] = result;
                }
            }
            return dp[start] = 0;
        };
        return go(0);
    }
};