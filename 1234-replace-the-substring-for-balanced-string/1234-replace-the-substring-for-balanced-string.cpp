class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        map<int,int> cnt;
        for(int i = 0 ; i < n ; i++){
            cnt[s[i]]++;
        }
        
        //we have count of 'q','w','e','r' in the cnt.
        int count = 0;
        for(auto &[a,b] : cnt){
            b = max(0,b-n/4);
            count += b;
        }
        if(count == 0) return 0;
        //now cnt knows how much each element is in access.
        
        //now it's time to find a window in the string s such that all
        //the characters that are in the access are covered in that substring.
        int en = 0;
        int st = 0;
        int ans = n;
        map<int,int> taken;
        while(en < n){
            if(count > 0){
                taken[s[en]]++;
                if(taken[s[en]] <= cnt[s[en]]){
                    count--;
                }
                en++;
            }
            //count = 0 means i have found a window such that it has all the elements
            //that are in the access.
            while(count == 0){
                ans = min(ans,en-st);
                taken[s[st]]--;
                if(taken[s[st]] < cnt[s[st]])
                    count++;
                st++;
            }
        }
        return ans;
    }
};