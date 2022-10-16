//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str){
        int n = str.size();
        bool cnt1[256] = {0};  //pattern 
        int cnt2[256] = {0};  //text
        
        int len = 0;
        for(auto x : str){
            if(!cnt1[x]) len++;
            cnt1[x] = true;
        }
        int en = 0;
        int st = 0;
        int count = 0;
        int ans = INT_MAX;
        while(en < n){
            if(count < len){
                cnt2[str[en]]++;
                if(cnt2[str[en]] == 1 && cnt1[str[en]]){
                    count++;
                }
                en++;
            }
            
            while(count == len){
                ans = min(ans,en-st);
                cnt2[str[st]]--;
                if(cnt2[str[st]] == 0 && cnt1[str[st]]){
                    count--;
                }
                st++;
            }
        }
        return (ans == INT_MAX)?0:ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends