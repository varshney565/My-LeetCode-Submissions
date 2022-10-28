class Solution {
public:
    //00100
    //01110
    //00010
    int totalHammingDistance(vector<int>& A) {
        int n = A.size();
        long long ans = 0;
        const int mod = 1e9+7;
        for(int i = 31 ; i >= 0 ; i--){
            long long c0 = 0,c1 = 0;
            for(int j = 0 ; j < n ; j++){
                if((1LL<<i)&A[j])
                    c1++;
                else
                    c0++;
            }
            ans = (ans+(c1*c0)%mod)%mod;
        }
        return ans;
    }
};