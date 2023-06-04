//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        function<int(int,int)> go = [&](int n,int sum){
            if(sum == 0) return dp[n][sum] = 1;
            if(n == 0) return dp[n][sum] = 0;
            if(dp[n][sum] != -1) return dp[n][sum];
            int ans = 0;
            //take 
            if(sum - arr[n-1] >= 0)
                ans += go(n-1,sum-arr[n-1]);
            if(ans) return dp[n][sum] = ans;
            //ignore
            ans += go(n-1,sum);
            return dp[n][sum] = ans;
        };
        return (go(n,sum) ? true : false);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends