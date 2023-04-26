class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        const int mod = 1e9+7;
        long long a = 1,b = 1;
        for(int i = 0 ; i < n ; i++){
            int c = 0;
            if(s[i] != '0') c = (b*(s[i] == '*' ? 9 : 1))%mod;
            if(i && s[i-1] != '0'){
                long long f = 1,num = (s[i-1]-'0')*10+(s[i]-'0');
                if(s[i] == '*' && s[i-1] == '*') f = 15;
                else if(s[i] == '*') f = (s[i-1] == '1' ? 9 : (s[i-1] == '2' ? 6 : 0));
                else if(s[i-1] == '*') f = (s[i] >= '0' && s[i] <= '6') ? 2 : 1;
                else if(!( num >= 1 && num <= 26 )) f = 0;
                c = (c + (f*a)%mod)%mod;
            }
            a = b;
            b = c;
        }
        return b;
    }
};