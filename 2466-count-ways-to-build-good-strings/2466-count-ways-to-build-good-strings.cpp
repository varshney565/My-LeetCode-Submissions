class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,0);
        const int mod = 1e9+7;
        dp[0] = 1;
        for(int i = 1 ; i <= high ; i++){
            dp[i] = ((long long)((i-one >= 0)?dp[i-one]:0)+((i-zero < 0)?0:dp[i-zero]))%mod;
        }
        int ans = 0;
        for(int i = low ; i <= high ; i++) ans = (ans + (long long)dp[i])%mod;
        return ans;
    }
};