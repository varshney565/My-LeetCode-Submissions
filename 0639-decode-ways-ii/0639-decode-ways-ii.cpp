class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        const int mod = 1e9+7;
        vector<int> dp(n,-1);
        function<int(int)> go = [&](int i){
            if(i < 0) return 1;
            if(dp[i] != -1) return dp[i];
            //consider only ith character
            int ans = 0;
            if(s[i] != '0') ans = ((long long)go(i-1)*(s[i] == '*' ? 9ll : 1ll))%mod;
            //consider both ith and (i-1)th character
            if(i){
                if(s[i-1] != '0'){
                    long long f = 1;
                    if(s[i] == '*' && s[i-1] == '*'){
                        f = 15;
                    }else if(s[i] == '*'){
                        f = (s[i-1] == '1') ? 9 : (s[i-1] == '2' ? 6 : 0);
                    }else if(s[i-1] == '*'){
                        f = (s[i] >= '0' && s[i] <= '6') ? 2 : 1;
                    }else{
                        int num = (s[i-1]-'0')*10 + (s[i]-'0');
                        if(!(num >= 1 && num <= 26))
                            f = 0;
                    }
                    if(f)
                        ans = (ans + (go(i-2)*f)%mod)%mod;
                }
            }
            return dp[i] = ans;
        };
        return go(n-1);
    }
};