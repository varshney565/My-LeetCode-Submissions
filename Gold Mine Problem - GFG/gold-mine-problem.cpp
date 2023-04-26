//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M){
        int dir[][2] = {{-1,-1},{0,-1},{1,-1}};
        vector<vector<int>> dp(n,vector<int>(m,-1));
        function<int(int,int)> go = [&](int x,int y){
            if(y == 0){
                return dp[x][y] = M[x][y];
            }
            if(dp[x][y] != -1) return dp[x][y];
            int ans = 0;
            for(int i = 0 ; i < 3 ; i++){
                int newx = x+dir[i][0];
                int newy = y+dir[i][1];
                if(newx >= 0 && newx < n && newy >= 0 && newy < m){
                    ans = max(ans,go(newx,newy));
                }
            }
            return dp[x][y] = ans+M[x][y];
        };
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            ans = max(ans,go(i,m-1));
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