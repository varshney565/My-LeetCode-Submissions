//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int v[]){
        // code here
        stack<int> s1;
        vector<int> ps(n,-1);
        for(int i = 0 ; i < n ; i++){
            while(!s1.empty() && v[s1.top()] >= v[i]){
                s1.pop();
            }
            if(!s1.empty()) ps[i] = v[s1.top()];
            s1.push(i);
        }
        return ps;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends