class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //find the maximum length subarray with atmost 2 different values.
        int n = fruits.size();
        int st = 0;
        int en = 0;
        map<int,int> cnt;
        int ans = 0;
        while(en < n){
            cnt[fruits[en]]++;
            while(cnt.size() > 2){
                cnt[fruits[st]]--;
                if(cnt[fruits[st]] == 0)
                    cnt.erase(fruits[st]);
                st++;
            }
            ans = max(ans,en-st+1);
            en++;
        }
        return ans;
    }
};