class Solution {
public:
    int totalStrength(vector<int>& strength) {
        int n = strength.size();
        vector<long long> next(n,n);
        vector<long long> prev(n,-1);
        auto nextSmaller = [&](){
            stack<long long> s;
            for(int i = n-1 ; i >= 0 ; i--){
                while(!s.empty() && strength[s.top()] >= strength[i]){
                    s.pop();
                }
                next[i] = ((s.empty())?n:s.top());
                s.push(i);
            }
        };
        
        auto prevSmaller = [&](){
            stack<long long> s;
            for(int i = 0 ; i < n ; i++){
                while(!s.empty() && strength[s.top()] > strength[i]){
                    s.pop();
                }
                prev[i] = ((s.empty())?-1:s.top());
                s.push(i);
            }
        };
        prevSmaller();
        nextSmaller();
        const int mod = 1e9+7;
        vector<long long> pre(n,0);
        for(int i = 0 ; i < n ; i++){
            pre[i] = strength[i];
            if(i){
                pre[i] += pre[i-1];
            }
            pre[i] %= mod;
        }
        
        vector<long long> preMul(n,0);
        vector<long long> sufMul(n,0);
        
        
        for(int i = 0 ; i < n ; i++){
            preMul[i] = (long long)(i+1LL)*strength[i];
            preMul[i] %= mod;
            if(i){
                preMul[i] += preMul[i-1];
            }
            preMul[i] %= mod;
        }
        for(int i = n-1 ; i >= 0 ; i--){
            sufMul[i] = (long long)strength[i]*(n-i);
            sufMul[i] %= mod;
            if(i < n-1){
                sufMul[i] += sufMul[i+1];
            }
            sufMul[i] %= mod;
        }
        
        long long ans = 0;
        for(int i = 0 ; i < n ; i++){
            long long L = prev[i];
            long long R = next[i];
            long long Lsize = i-L;
            long long Rsize = R-i;
            long long LeftSum = pre[i];
            if(L >= 0)
                LeftSum -= pre[L];
            
            LeftSum = (LeftSum+mod)%mod;
            LeftSum *= (L+1LL);
            LeftSum %= mod;
            long long RightSum = ((n-R)*((pre[R-1]-pre[i]+mod)%mod))%mod;
            long long RightMul = 0;
            if(i + 1 < n){
                RightMul = sufMul[i+1]+mod;
                if(R < n){
                    RightMul -= sufMul[R];
                }
                
                RightMul %= mod;
                RightMul -= RightSum;
                RightMul += mod;
                RightMul %= mod;
            }
            RightMul *= Lsize;
            RightMul %= mod;
            long long LeftMul  = preMul[i]+mod;
            if(L >= 0)
                LeftMul -= preMul[L];
            LeftMul %= mod;
            LeftMul -= LeftSum;
            LeftMul += mod;
            LeftMul *= Rsize;
            LeftMul %= mod;
            ans += (LeftMul+RightMul)*strength[i];
            ans %= mod;
        }
        return ans;
    }
};