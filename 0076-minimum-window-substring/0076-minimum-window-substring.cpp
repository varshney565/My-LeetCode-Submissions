class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int s1[256] = {0};
        int s2[256] = {0};
        //finding the frequency of each character in pattern.
        for(int i = 0 ; i < t.size() ; i++){
            s1[t[i]]++;
        }
        
        int count = 0;
        int en = 0;
        int st = 0;
        int len = 1e9;
        int sp = -1;
        while(en < s.size()){
            if(count < t.size()){
                s2[s[en]]++;
                if(s2[s[en]] <= s1[s[en]]){
                    count++;
                }
                en++;
            }
            while(count == t.size()){
                //count is equal to t.size()
                //means all the characters of t are present in s.
                //st-------i-1
                if(len > en-st){
                    len = en-st;
                    sp = st;
                }
                s2[s[st]]--;
                if(s2[s[st]] < s1[s[st]]){
                    count--;
                }
                st++;
            }
        }
        if(len == 1e9) return "";
        return s.substr(sp,len);
    }
};