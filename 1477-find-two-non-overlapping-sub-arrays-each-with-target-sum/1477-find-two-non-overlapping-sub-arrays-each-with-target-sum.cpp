class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> pre(n,n),suf(n,n);
        unordered_map<int,int> F;
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += arr[i];
            if(sum == target){
                pre[i] = i + 1;
            }
            if(F.find(sum-target) != F.end()){
                pre[i] = i - F[sum-target];
            }
            F[sum] = i;
        }
        F.clear();
        sum = 0;
        for(int i = n - 1 ; i >= 0 ; i--){
            sum += arr[i];
            if(sum == target){
                suf[i] = n - i;
            }
            if(F.find(sum - target) != F.end()){
                suf[i] = F[sum - target] - i;
            }
            F[sum] = i;
        }
        for(int i = 0 ; i < n ; i++){
            if(i) pre[i] = min(pre[i - 1],pre[i]);
        }
        for(int i = n - 1 ; i >= 0 ; i--){
            if(i < n - 1) suf[i] = min(suf[i],suf[i + 1]);
        }
        int ans = INT_MAX;
        for(int i = 1 ; i < n ; i++){
            ans = min(ans,pre[i - 1]+suf[i]);
        }
        return ans>n?-1:ans;
    }
};