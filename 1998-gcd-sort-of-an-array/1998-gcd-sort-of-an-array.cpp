class dsu{
    public:
    vector<int> p;
    dsu(int n){
        p.resize(n);
        iota(p.begin(),p.end(),0);
    }
    
    int get(int n){
        if(p[n] == n) return n;
        return p[n] = get(p[n]);
    }
    
    bool unite(int a,int b){
        int p1 = get(a);
        int p2 = get(b);
        if(p1 == p2){
            return false;
        }
        p[p1] = p2;
        return true;
    }
};

class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        int MAX = INT_MIN;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > MAX)
                MAX = nums[i];
        }
        vector<int> spf(MAX+1);
        iota(spf.begin(),spf.end(),0);
        for(long long i = 2 ; i <= MAX ; i++){
            if(spf[i] != i){
                continue;
            }
            for(long long j = i*i ; j <= MAX ; j += i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
        
        dsu D(MAX+1);
        for(int i = 0 ; i < n ; i++){
            int v = nums[i];
            while(v > 1){
                int f = spf[v];
                D.unite(f,nums[i]);
                while(v%f == 0){
                    v = v/f;
                }
            }
        }
        vector<int> sortedArray = nums;
        sort(sortedArray.begin(),sortedArray.end());
        for(int i = 0 ; i < n ; i++){
            if(D.unite(sortedArray[i],nums[i]))
                return false;
        }
        return true;
    }
};