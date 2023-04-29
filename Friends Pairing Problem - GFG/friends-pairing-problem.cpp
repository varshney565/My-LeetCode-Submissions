//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    const int mod = 1e9+7;
    int countFriendsPairings(int n){
        vector<int> dp(n+1,-1);
        
        function<int(int)> go = [&](int n){
            if(n <= 1) return dp[n] = 1;
            if(dp[n] != -1) return dp[n];
            int single = go(n-1);
            int paired = ((n >= 2) ? ((n-1)*(long long)go(n-2))%mod : 0);
            return dp[n] = (single+paired)%mod;
        };
        return go(n);
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends