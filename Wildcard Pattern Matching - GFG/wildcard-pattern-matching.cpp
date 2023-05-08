//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(string p,string s){
        /**
        ? --> one char
        . --> any sequence of chars
        */
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        function<int(int,int)> go = [&](int n,int m){
            if(n == 0 && m == 0) return dp[n][m] = 1;
            if(m == 0) return dp[n][m] = 0;
            if(n == 0){
                for(int i = m - 1 ; i >= 0 ; i--){
                    if(p[i] != '*') return dp[n][m] = 0;
                }
                return dp[n][m] = 1;
            }
            
            if(dp[n][m] != -1) return dp[n][m];
            
            if(p[m-1] == '?' || p[m-1] == s[n-1]){
                return dp[n][m] = go(n-1,m-1);
            }else if(p[m-1] == '*'){
                return dp[n][m] = (go(n,m-1) || go(n-1,m)) ? 1 : 0;
            }
            return dp[n][m] = 0;
        };
        return go(n,m);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends