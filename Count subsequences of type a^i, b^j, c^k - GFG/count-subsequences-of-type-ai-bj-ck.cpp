//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        vector<int> cnt(3,0);
        int n = s.size();
        const int mod = 1e9+7;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'a') cnt[0] = ((2*cnt[0])%mod+1)%mod;
            else cnt[s[i]-'a'] = ((2*cnt[s[i]-'a'])%mod+cnt[s[i]-'a'-1])%mod;
        }
        return cnt[2];
    }
};

//{ Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends