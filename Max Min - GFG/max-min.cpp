//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
   public:
    pair<int,int> helper(int *nums,int si,int ei){
        //tournament method.
        if(si > ei){
            return {INT_MAX,INT_MIN};
        }
        
        if(si == ei){
            return {nums[si],nums[ei]};
        }
        int mid = (si+ei)/2;
        auto left  = helper(nums,si,mid);
        auto right = helper(nums,mid+1,ei);
        pair<int,int> ans;
        ans.first  = min(left.first,right.first);
        ans.second = max(left.second,right.second);
        return ans;
    }
   
    int findSum(int num[], int n)
    {
    	auto it = helper(num,0,n-1);
    	return it.first+it.second;
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
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	    Solution ob;  
	    int ans=ob.findSum(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends