class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int ans = 0;
        vector<int> dp(n,-1);
        function<int(int)> go = [&](int i){
            if(i < 0) return 1;
            if(dp[i] != -1) return dp[i];
            int ans = 0;
            //consider only ith character.
            int num = s[i]-'0';
            if(num >= 1 && num <= 9){
                ans += go(i-1);
            }
            //consider both ith and (i-1)th character.
            if(i){
                int num2 = s[i-1]-'0';
                if(num2){
                    int number = num2*10+num;
                    if(number >= 1 && number <= 26)
                        ans += go(i-2);
                }
            }
            return dp[i] = ans;
        };
        return go(n-1);
    }
};