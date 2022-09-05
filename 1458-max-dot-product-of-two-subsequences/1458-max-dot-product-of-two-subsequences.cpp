class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        function<int(int,int)> go = [&](int n,int m){
            //Base Case...
            if(n == 0 || m == 0)
                return dp[n][m] = 0;
            if(dp[n][m] != -1) return dp[n][m];
            int res = INT_MIN;
            //take both n-1 and m-1 character
            res = max(res,nums1[n-1]*nums2[m-1]+go(n-1,m-1));
            //take n-1 char and ignore m-1
            res = max(res,go(n,m-1));
            //ignore n-1 char and take m-1
            res = max(res,go(n-1,m));
            //ignore n-1 and m-1
            //this case handled in case 2 and case 3 already
            //no need to call for this test case
            return dp[n][m] = res;
        };
        int ans = go(n,m);
        if(nums1[0] < 0){
            sort(nums1.begin(),nums1.end(),greater<int>());
            sort(nums2.begin(),nums2.end());
        }else{
            sort(nums1.begin(),nums1.end());
            sort(nums2.begin(),nums2.end(),greater<int>());
        }
        int val = nums1[0]*nums2[0];
        return ((ans==0)?val:ans);
    }
};