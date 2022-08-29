class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        function<int(int)> go = [&](int st){
            if(st == n)
                return 1;
            if(s[st] == '0')
                return 0;
            if(dp[st] != -1)
                return dp[st];
            int ans = 0;
            int Num1 = s[st]-'0';
            ans += go(st+1);
            if(st+1 < n){
                int Num2 = (s[st]-'0')*10+s[st+1]-'0';
                if(Num2 <= 26)
                    ans += go(st+2);
            }
            return dp[st] = ans;
        };
        int ans = go(0);
        return ans;
    }
};