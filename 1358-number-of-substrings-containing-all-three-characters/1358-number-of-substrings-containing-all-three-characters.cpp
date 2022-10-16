class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int st = 0;
        int en = 0;
        map<int,int> cnt;
        int ans = 0;
        while(en < n){
            cnt[s[en]]++;
            while(cnt.size() == 3){
                ans += (n-en);
                cnt[s[st]]--;
                if(cnt[s[st]] == 0)
                    cnt.erase(s[st]);
                st++;
            }
            en++;
        }
        return ans;
    }
};