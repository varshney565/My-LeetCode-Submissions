class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int ans = 0;
        for(int i = 1 ; i <= 26 ; i++){
            //i means total unique elements in the subtring.
            int st = 0;
            int en = 0;
            map<int,int> f;
            while(en < n){
                f[s[en]]++;
                while(f.size() > i){
                    f[s[st]]--;
                    if(f[s[st]] == 0)
                        f.erase(s[st]);
                    st++;
                }
                if(f.size() == i){
                    bool ok = true;
                    for(auto &[a,b] : f){
                        if(b < k){
                            ok = false;
                            break;
                        }
                    }
                    if(ok)
                        ans = max(ans,en-st+1);
                }
                en++;
            }
        }
        return ans;
    }
};