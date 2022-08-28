class Solution {
public:
    int climbStairs(int n) {
        vector<int> t(n+1,-1);
        function<int(int)> dfs = [&](int n){
            if(n == 0 || n == 1){
                return 1;
            }
            if(t[n] != -1) return t[n];
            int ans = dfs(n-1)+dfs(n-2);
            return t[n] = ans;
        };
        int ans = dfs(n);
        return ans;
    }
};