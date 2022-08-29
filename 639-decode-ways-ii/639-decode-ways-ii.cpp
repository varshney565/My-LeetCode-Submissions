class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        const int mod = 1e9+7;
        function<int(int)> go = [&](int st){
            if(st == n)
                return 1;
            if(s[st] == '0')
                return 0;
            if(dp[st] != -1) return dp[st];
            long long ans = 0;
            if(s[st] == '*'){
                //taking one
                //* | anything
                //* ans += 9*ans(st+1)
                ans += (9LL*go(st+1))%mod;
                
                if(st+1 < n){
                    int r = go(st+2);
                    if(s[st+1] != '*'){
                        //taking two 
                        //* num
                        //* --> num <= 6  ans += 2*ans(st+2)
                        //      num >  6  ans += ans(st+2)
                        if(s[st+1] <= '6'){
                            ans += (2LL*r)%mod;
                        }else{
                            ans += r;
                        }
                    }else{
                        //* * posibilities = 17
                        ans += (15LL*r)%mod;
                    }
                }
            }else{
                //num | anything
                ans += go(st+1);
                if(st+1 < n){
                    int r = go(st+2);
                    if(s[st+1] == '*'){
                        //num *
                        int num = s[st]-'0';
                        if(num == 1LL){
                            ans += (9LL*r)%mod;
                        }else if(num == 2LL){
                            ans += (6LL*r)%mod;
                        }
                    }else{
                        //num num
                        int num = (s[st]-'0')*10LL+(s[st+1]-'0');
                        if(num <= 26LL)
                            ans += r;
                    }
                }
            }
            ans %= mod;
            return dp[st] = (int)ans;
        };
        return go(0);
    }
};