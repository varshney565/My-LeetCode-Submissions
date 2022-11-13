class Solution {
public:
    
    void merge(vector<int> &nums,vector<int> &idx,vector<int> &ans,int si,int mid,int ei){
        vector<int> res(ei-si+1);
        vector<int> res2(ei-si+1);
        int i = si;
        int j = mid+1;
        int k = 0;
        while(i <= mid && j <= ei){
            if(nums[i] > nums[j]){
                res[k] = nums[j];
                res2[k++] = idx[j++];
            }else{
                ans[idx[i]] += j-mid-1;
                res[k] = nums[i];
                res2[k++] = idx[i++];
            }
        }
        
        while(i <= mid){
            ans[idx[i]] += j-mid-1;
            res[k] = nums[i];
            res2[k++] = idx[i++];
        }
        
        while(j <= ei){
            res[k] = nums[j];
            res2[k++] = idx[j++];
        }
        
        for(int i = si ; i <= ei ; i++){
            nums[i] = res[i-si];
            idx[i] = res2[i-si];
        }
    }
    
    void merge_sort(vector<int> &nums,vector<int> &idx,vector<int> &ans,int si,int ei){
        if(si >= ei) return;
        
        int mid = si+(ei-si)/2;
        merge_sort(nums,idx,ans,si,mid);
        merge_sort(nums,idx,ans,mid+1,ei);
        merge(nums,idx,ans,si,mid,ei);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        vector<int> idx(nums.size(),0);
        for(int i = 0 ; i < nums.size() ; i++)  idx[i] = i;
        merge_sort(nums,idx,ans,0,nums.size()-1);
        return ans;
    }
};