long long max(long long a,long long b){
    return (a<b)?b:a;
}
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        /**
        a) a1 a2 a3 a4 a5
        b) (part of a1) a2 a3 a4 (part of a5)
        c) maximum circuler subarray sum
        */
        int n = arr.size();
        int gsum = 0;
        for(int i = 0 ; i < n ; i++){
            gsum += arr[i];
        }
        const int mod = 1e9+7;
        
        
        int sum = 0;
        int gMax = 0;
        int cMaxSum = 0;
        int maxSuf = gsum;
        int maxPre = 0;
        for(int i = 0 ; i < n ; i++){
            sum += arr[i];
            maxSuf = max(maxSuf,gsum-sum);
            maxPre = max(sum,maxPre);
            cMaxSum = max(cMaxSum+arr[i],arr[i]);
            gMax = max(gMax,cMaxSum);
        }
        
        if(k == 1) return gMax;
        long long ans = (max(max(0ll,(long long)(k-2)*sum)+maxSuf+maxPre,gMax))%mod;
        return ans;
    }
};