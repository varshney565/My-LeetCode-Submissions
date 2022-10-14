class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        map<int,int> cnt;
        int ans = 0;
        while(i < n){
            cnt[s[i]]++;
            while(cnt[s[i]] > 1){
                cnt[s[j]]--;
                j++;
            }
            ans = max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};