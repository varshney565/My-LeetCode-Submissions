class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int mod = 1e9+7;
        vector<vector<vector<int>>> dp(profit.size(),vector<vector<int>>(minProfit+1,vector<int>(n+1,-1)));
        function<int(int,int,int)> go = [&](int i,int minPro,int peopleRemaining){
            if(peopleRemaining < 0){
                return 0;
            }
            //base case
            if(i < 0){
                if(minPro == 0 && peopleRemaining >= 0) return 1;
                return 0;
            }
            if(dp[i][minPro][peopleRemaining] != -1) return dp[i][minPro][peopleRemaining];
            //recursive call
            int ans = 0;
            //do the crime
            ans = (ans + go(i-1,max(0,minPro-profit[i]),peopleRemaining-group[i]))%mod;
            //don't do the crime
            ans = (ans + go(i-1,minPro,peopleRemaining))%mod;
            return dp[i][minPro][peopleRemaining] = ans;
        };
        return go(profit.size()-1,minProfit,n);
    }
};