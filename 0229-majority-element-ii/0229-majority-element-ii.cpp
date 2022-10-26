class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        /**
        
            (n/3+1)*3 = n+3 > n (not possible)
            
            there can be atmost 2 majority elements.
        
        **/
        int n = nums.size();
        int cnt1 = 0;
        int cnt2 = 0;
        int num1 = INT_MIN;
        int num2 = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == num1)
                cnt1++;
            else if(nums[i] == num2)
                cnt2++;
            else if(cnt1 == 0){
                cnt1++;
                num1 = nums[i];
            }else if(cnt2 == 0){
                cnt2++;
                num2 = nums[i];
            }else{
                cnt1--;
                cnt2--;
            }
        }
        int f1 = 0;
        int f2 = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == num1)
                f1++;
            if(nums[i] == num2)
                f2++;
        }
        vector<int> ans;
        if(f1 > n/3)
            ans.push_back(num1);
        if(f2 > n/3)
            ans.push_back(num2);
        return ans;
    }
};