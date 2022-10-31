//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        int *right = new int[n];
        right[n-1] = n-1;
        for(int j = n-2 ; j >= 0 ; j--){
            if(arr[right[j+1]] >= arr[j] ) right[j] = right[j+1];
            else right[j] = j;
        }
        int i = 0,j = 0;
        int ans = 0;
        while(i < n  && j < n){
            if(arr[i] <= arr[right[j]]){
                ans = max(ans,right[j]-i);
                j++;
            }else{
                i++;
            }
        }
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends