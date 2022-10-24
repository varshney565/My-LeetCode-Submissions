class Solution {
public:
    int findMax(vector<int> &nums,int k){
        int m = nums.size();
        int ans = (int)-1e9;
        //find the maximum sum of subarray with sum atmost k
        int sum = 0;
        int en = 0;
        set<int> container;
        container.insert(0);
        while(en < m){
            sum += nums[en];
            auto it = container.lower_bound(sum-k);
            if(it != container.end())
                ans = max(ans,sum-*it);
            container.insert(sum);
            en++;
        }
        return ans;
    }
    
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = (int)-1e9;
        for(int i = 0 ; i < m ; i++){
            vector<int> RowSum(n,0);
            for(int j = i ; j < m ; j++){
                for(int k = 0 ; k < n ; k++)
                    RowSum[k] += matrix[k][j];
                ans = max(ans,findMax(RowSum,k));
            }
        }
        return ans;
    }
};