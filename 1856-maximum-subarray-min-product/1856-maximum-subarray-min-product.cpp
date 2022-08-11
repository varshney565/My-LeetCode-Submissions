class SegTree{ 
    public:
    vector<int> s;
    vector<int> v;
    SegTree(vector<int> ve){
        int n = ve.size();
        s.resize(4*n,0);
        v.insert(v.end(),ve.begin(),ve.end());
    }
    
    int get(int st,int en,int ind,int i,int j){
        if(i > en || j < st)
            return -1;
        if(i <= st && j >= en){
            return s[ind];
        }
        int mid = ((st+en)>>1);
        int Lans = get(st,mid,2*ind+1,i,j);
        int Rans = get(mid+1,en,2*ind+2,i,j);
        if(Lans == -1) return Rans;
        if(Rans == -1) return Lans;
        return ((v[Lans] < v[Rans])?Lans:Rans);
    }
    
    void build(int st,int en,int ind){
        if(st > en) return;
        if(st == en){
            s[ind] = st;
            return;
        }
        int md = ((st+en)>>1);
        build(st,md,2*ind+1);
        build(md+1,en,2*ind+2);
        s[ind] = ((v[s[2*ind+1]] < v[s[2*ind+2]])?s[2*ind+1]:s[2*ind+2]);
    }
};


class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        const int mod = 1e9+7;
        SegTree Seg(nums);
        Seg.build(0,n-1,0);
        vector<long long> pre(n,0);
        for(int i = 0 ; i < n ; i++){
            pre[i] += nums[i];
            if(i-1 >= 0){
                pre[i] += pre[i-1];
            }
        }
        long long ans = 0;
        function<void(int,int)> go = [&](int s,int e){
            if(s > e)
                return;
            int mnId = Seg.get(0,n-1,0,s,e);
            long long sum = pre[e];
            if(s > 0)
                sum -= pre[s-1];
            long long t = (sum*nums[mnId]);
            ans = max(ans,t);
            go(s,mnId-1);
            go(mnId+1,e);
        };
        go(0,n-1);
        ans %= mod;
        return (int)ans;
    }
};