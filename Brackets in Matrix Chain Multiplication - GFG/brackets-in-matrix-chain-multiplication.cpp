//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string matrixChainOrder(int p[], int n){
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = 0 ; j < n ; j++){
                if(j-i == 1) {
                    dp[i][j] = 1;
                    continue;
                }
                for(int cut = i+1 ; cut < j ; cut++){
                    dp[i][j] = min(dp[i][j],dp[i][cut]+dp[cut][j]+p[i]*p[cut]*p[j]);
                }
            }
        }
        
        function<string(int,int)> go = [&](int st,int en){
            if(en - st == 1) {
                string t = "";
                t += char('A'+st);
                return t;
            }
            string ans = "";
            for(int cut = st + 1 ; cut < en ; cut++){
                if(dp[st][en] == dp[st][cut]+dp[cut][en]+p[st]*p[cut]*p[en]){
                    string lans = go(st,cut);
                    string rans = go(cut,en);
                    ans = "("+lans+rans+")";
                    break;
                }
            }
            return ans;
        };
        return go(0,n-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends