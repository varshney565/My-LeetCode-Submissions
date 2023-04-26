//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> Matrix)
    {
        int dir[][2] = {{1,0},{1,-1},{1,1}};
        vector<vector<int>> dp(n,vector<int>(n,-1));
        function<int(int,int)> go = [&](int x,int y){
            if(x == n-1) return dp[x][y] = Matrix[x][y];
            if(dp[x][y] != -1) return dp[x][y];
            int ans = 0;
            for(int i = 0 ; i < 3 ; i++){
                int newx = x+dir[i][0];
                int newy = y+dir[i][1];
                if(newx >= 0 && newx < n && newy >= 0 && newy < n){
                    ans = max(ans,go(newx,newy));
                }
            }
            return dp[x][y] = ans + Matrix[x][y];
        };
        int ans = 0;
        for(int j = 0 ; j < n ; j++){
            ans = max(ans,go(0,j));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends