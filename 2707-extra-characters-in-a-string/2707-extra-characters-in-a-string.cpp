class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        set<string> se;
        for(auto x : dictionary){
            se.insert(x);
        }
        
        vector<int> dp(n+1,-1);
        function<int(int)> go = [&](int n){
            if(n == 0) return dp[n] = 0;
            if(dp[n] != -1) return dp[n];
            int ans = n;
            //take the last char
            string tmp = "";
            for(int i = n - 1 ; i >= 0 ; i--){
                tmp = s[i] + tmp;
                if(se.find(tmp) != se.end()){
                    ans = min(ans,go(i));
                }
            }
            //ignore the last char
            ans = min(ans,go(n-1)+1);
            return dp[n] = ans;
        };
        return go(n);
    }
};