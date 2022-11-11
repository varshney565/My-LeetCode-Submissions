/**
    Using policy based data structure.
*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        ordered_set store;
        for(int i = n-1 ; i >= 0 ; i--){
            ans[i] = store.order_of_key(nums[i]);
            store.insert(nums[i]);
        }
        return ans;
    }
};