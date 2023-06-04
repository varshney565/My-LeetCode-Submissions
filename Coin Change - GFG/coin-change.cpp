//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int v[], int N, int T) {
        vector<long long> dp(T+1,0);
    	for(int n = 1 ; n <= N ; n++){
    		vector<long long> dp2(T+1,0);
    		for(int target = 0 ; target <= T ; target++){
    			if(target == 0) {
    				dp2[target] = 1;
    				continue;
    			}
    			long long count = 0;
    			if(target-v[n-1] >= 0)
    				count += dp2[target-v[n-1]];
    			if(n > 1)
    				count += dp[target];
    			dp2[target] = count;
    		}
    		swap(dp2,dp);
    	}
    	return dp[T];
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