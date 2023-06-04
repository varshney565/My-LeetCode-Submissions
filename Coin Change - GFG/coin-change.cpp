//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int v[], int N, int T) {
        vector<vector<long long>> dp(N+1,vector<long long>(T+1,0));
    	for(int n = 1 ; n <= N ; n++){
    		for(int target = 0 ; target <= T ; target++){
    			if(target == 0) {
    				dp[n][target] = 1;
    				continue;
    			}
    			long long count = 0;
    			if(target-v[n-1] >= 0)
    				count += dp[n][target-v[n-1]];
    			if(n > 1)
    				count += dp[n-1][target];
    			dp[n][target] = count;
    		}
    	}
    	return dp[N][T];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends