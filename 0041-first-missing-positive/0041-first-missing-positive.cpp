class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*
        -ve elements including 0 + all the elements that are greater than n will be a waste 
        so just do the ans for elements that are in range [1,n]
        'and use -ve base indexing techinique'
        */
        int n = nums.size();
        /**
        Task 1 : 
            Segregate neagitive and positive elements.
        */
        int i = -1;
        int j = 0;
        while(j < n){
            if(nums[j] <= 0 || nums[j] > n){
                i++;
                nums[j] = nums[i];
                nums[i] = n;
            }
            j++;
        }
        /**
        so all elements till ith index now have values less than or equal to zero or values greater than n.
        */
        for(int j = i + 1 ; j < n ; j++){
            int idx = abs(nums[j])-1;
            if(nums[idx] > 0)
                nums[idx] *= -1;
        }
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > 0) return i+1;
        }
        return n+1;
    }
};