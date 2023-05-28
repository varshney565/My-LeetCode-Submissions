class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        set<string> Dict;
        for(auto x : wordDict) Dict.insert(x);
        vector<int> dp(n+1,-1);
        function<int(int)> go = [&](int n){
            if(n == 0) return dp[n] = 1;
            if(dp[n] != -1) return dp[n];
            string word = "";
            bool ans = false;
            for(int i = n - 1 ; i >= 0 ; i--){
                word = s[i] + word;
                if(Dict.find(word) != Dict.end()){
                    ans = go(i) || ans;
                }
            }
            return dp[n] = (ans?1:0);
        };
        return go(n);
    }
};