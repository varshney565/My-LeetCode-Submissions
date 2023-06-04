//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int v[], int N, int T) {
    	vector<long long> dp(T+1,0);
    	dp[0] = 1;
    	for(int n = 1 ; n <= N ; n++){
    		for(int target = v[n-1] ; target <= T ; target++){
    			if(target-v[n-1] >= 0)
    				dp[target] += dp[target-v[n-1]];
    		}
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