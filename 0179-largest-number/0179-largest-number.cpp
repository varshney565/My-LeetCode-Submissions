class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](int a,int b){
            string A = to_string(a);
            string B = to_string(b);
            return (A+B > B+A);
        });
        string ans = "";
        for(auto x : nums){
            if(ans.size() == 0 && !x)
                return "0";
            ans += to_string(x);
        }
        return ans;
    }
};