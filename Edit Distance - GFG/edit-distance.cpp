//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        function<int(int,int)> go = [&](int n,int m){
            if(n == 0 || m == 0){
                return dp[n][m] = max(n,m);
            }
            if(dp[n][m] != -1) return dp[n][m];
            int ans = 1e4;
            if(s[n-1] == t[m-1]){
                ans = go(n-1,m-1);
            }else{
                int ch1 = 1+go(n-1,m-1);
                int ch2 = 1+go(n-1,m);
                int ch3 = 1+go(n,m-1);
                ans = min({ans,ch1,ch2,ch3});
            }
            return dp[n][m] = ans;
        };
        return go(n,m);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends