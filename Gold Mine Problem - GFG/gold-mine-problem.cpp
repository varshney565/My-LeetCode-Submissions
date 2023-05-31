//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dir[3][2] = {{-1,1},{1,1},{0,1}};
    int maxGold(int n, int m, vector<vector<int>> M){
        vector<vector<int>> dp(n,vector<int>(m,-1));
        function<int(int,int)> go = [&](int i,int j){
            if(j == m-1){
                return dp[i][j] = M[i][j];
            }
            if(dp[i][j] != -1) return dp[i][j];
            int val = 0;
            for(int x = 0 ; x < 3 ; x++){
                int newi = i+dir[x][0];
                int newj = j+dir[x][1];
                if(newi >= 0 && newi < n && newj >= 0 && newj < m){
                    int t = go(newi,newj);
                    val = max(val,t);
                }
            }
            return dp[i][j] = val + M[i][j];
        };

        int ans = 0;
        int ind = -1;
        for(int i = 0 ; i < n ; i++){
            int t = go(i,0);
            if(ans < t){
                ans = t;
                ind = i;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends