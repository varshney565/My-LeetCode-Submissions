//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int go(int i,int mask,vector<vector<int>> &cost){
        if(mask == 0){
            return dp[i][mask] = cost[i][0];
        }
        
        if(dp[i][mask] != -1) return dp[i][mask];
        int answer = INT_MAX;
        for(int j = 0 ; j < n ; j++){
            if((1<<j)&mask){
                answer = min(answer,cost[i][j] + go(j,mask^(1<<j),cost));
            }
        }
        return dp[i][mask] = answer;
    };
    
    int total_cost(vector<vector<int>>cost){
        n = cost.size();
        dp.resize(n,vector<int>(1<<n,-1));
        return go(0,(1<<n)-2,cost);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends