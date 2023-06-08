class Solution {
public:
    int N;
    bool go(vector<int> &nums,vector<bool> &visited,int n,int k,int sumSF,int target){
        if(k == 0) return true;
        if(sumSF == target){
            return go(nums,visited,N,k-1,0,target);
        }
        if(n == 0) return false;
        //already visited
        if(visited[n-1])
            return go(nums,visited,n-1,k,sumSF,target);
        //ignore
        if(go(nums,visited,n-1,k,sumSF,target)) return true;
        //take
        if(sumSF + nums[n-1] <= target){
            visited[n-1] = true;
            bool res = go(nums,visited,n-1,k,sumSF + nums[n-1],target);
            if(res) return true;
            visited[n-1] = false;
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        N = n;
        sum = accumulate(nums.begin(),nums.end(),sum);
        int max_ = *(max_element)(nums.begin(),nums.end());
        if(sum % k || max_ > sum/k) return false;
        vector<bool> visited(n,false);
        int tar = sum/k;
        return go(nums,visited,n,k,0,tar);
    }
};