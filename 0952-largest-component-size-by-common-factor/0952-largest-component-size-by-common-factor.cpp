class dsu{
  public:
    vector<int> p;
    vector<int> s;
    dsu(int n,vector<int> nums){
        p.resize(n);
        iota(p.begin(),p.end(),0);
        s.resize(n);
        for(auto x : nums) s[x] = 1;
    }
    
    int parent(int n){
        if(p[n] == n) return n;
        return p[n] = parent(p[n]);
    }
    
    bool unite(int a,int b){
        int p1 = parent(a);
        int p2 = parent(b);
        if(p1 == p2) return false;
        p[p1] = p2;
        s[p2] += s[p1];
        return true;
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        dsu d(1e5+1,nums);
        vector<int> spf(1e5+1,0);
        for(int i = 2 ; i <= 1e5 ; i++){
            if(spf[i])
                continue;
            for(int j = i ; j <= 1e5 ; j += i){
                if(spf[j]) continue;
                spf[j] = i;
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            int num = nums[i];
            int j = spf[num];
            while(num > 1){
                bool ok = false;
                while(num%j == 0){
                    ok = true;
                    num = num/j;
                }
                if(ok) d.unite(j,nums[i]);
                j = spf[num];
            }
        }
        int ans = 0;
        for(int i = 0 ; i <= 1e5 ; i++){
            ans = max(ans,d.s[i]);
        }
        return ans;
    }
};