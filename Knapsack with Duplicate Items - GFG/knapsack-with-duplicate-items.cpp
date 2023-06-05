//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[]){
        // code here
        vector<vector<int>> dp(N+1,vector<int>(W+1,-1));
        function<int(int,int)> go = [&](int n,int weight){
            if(n == 0 || weight == 0) return dp[n][weight] = 0;
            if(dp[n][weight] != -1) return dp[n][weight];
            int value = 0;
            //take 
            if(weight-wt[n-1] >= 0)
                value = val[n-1] + go(n,weight-wt[n-1]);
            //ignore
            value = max(value,go(n-1,weight));
            return dp[n][weight] = value;
        };
        return go(N,W);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends