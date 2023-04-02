class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans(spells.size());
        for(int i = 0 ; i < spells.size() ; i++){
            int n = potions.size();
            int s = 0;
            int e = n-1;
            long long t = ceil(success*1.0/spells[i]);
            //find the lower bound of t
            while(s <= e){
                int mid = s+(e-s)/2;
                if(potions[mid] >= t){
                    e = mid-1;
                }else{
                    s = mid+1;
                }
            }
            ans[i] = n-s;
        }
        return ans;
    }
};