//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
        int min(int a,int b){
            if(abs(a) < abs(b)){
                return a;
            }else if(abs(a) > abs(b)){
                return b;
            }
            return a > b?a:b;
        }
    
        int closestToZero(int arr[], int n)
        {
            // your code here 
            vector<int> pos,neg;
            for(int i = 0 ; i < n ; i++){
                if(arr[i] < 0){
                    neg.push_back(arr[i]);
                }else{
                    pos.push_back(arr[i]);
                }
            }
            
            sort(pos.begin(),pos.end());
            sort(neg.begin(),neg.end());
            
            int ans = INT_MAX;
            for(auto x : neg){
                int val = abs(x);
                auto it = upper_bound(pos.begin(),pos.end(),val)-pos.begin();
                if(it != pos.size())
                    ans = min(ans,x+pos[it]);
                if(it > 0){
                    ans = min(ans,x+pos[it-1]);
                }
            }
            if(pos.size() >= 2)
                ans = min(ans,pos[0]+pos[1]);
            if(neg.size() >= 2)
                ans = min(ans,neg[neg.size()-1]+neg[neg.size()-2]);
            return ans;
        }
};

//{ Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}
// } Driver Code Ends