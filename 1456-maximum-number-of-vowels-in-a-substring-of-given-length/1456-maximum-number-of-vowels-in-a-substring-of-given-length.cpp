class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        
        int count = 0;
        //checking whether a character is vowel or not.
        auto isV = [&](char a){
            if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
                return true;
            return false;
        };
        //some precalculations
        for(int i = 0 ; i < k ; i++){
            if(isV(s[i]))
                count++;
        }
        int ans = count;
        int st = 0;
        int en = k;
        while(en < n){
            if(isV(s[st])) count--;
            st++;
            if(isV(s[en])) count++;
            en++;
            ans = max(ans,count);
        }
        return ans;
    }
};