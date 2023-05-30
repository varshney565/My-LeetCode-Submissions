class SegTree{
    public:
    vector<int> p,v;
    void build(int cur_l,int cur_r,int ind){
        if(cur_l == cur_r){
            p[ind] = v[cur_l];
            return;
        }
        int mid = cur_l+(cur_r-cur_l)/2;
        build(cur_l,mid,2*ind+1);
        build(mid+1,cur_r,2*ind+2);
        p[ind] = p[2*ind+1]+p[2*ind+2];
    }
    
    int query(int cur_l,int cur_r,int ind,int L,int R){
        //no overlap 
        if(cur_l > R || cur_r < L) return 0;
        //complete overlap
        if(cur_l >= L && cur_r <= R) return p[ind];
        //else case
        int mid = cur_l+(cur_r-cur_l)/2;
        int left = query(cur_l,mid,2*ind+1,L,R);
        int right = query(mid+1,cur_r,2*ind+2,L,R);
        return left+right;
    }
    
    void update(int cur_l,int cur_r,int ind,int v_i,int val){
        if(cur_l == cur_r){
            v[v_i] = val;
            p[ind] = val;
            return;
        }
        int mid = cur_l+(cur_r-cur_l)/2;
        if(v_i <= mid)
            update(cur_l,mid,2*ind+1,v_i,val); //left call
        else
            update(mid+1,cur_r,2*ind+2,v_i,val); //right call;
        p[ind] = p[2*ind+1]+p[2*ind+2];
    }
    
    SegTree(int n){
        v.resize(n,1);
        p.resize(4*n,0);
        build(0,n-1,0);
    }
};

class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = nums.size();
        SegTree S(nums.size());
        vector<vector<int>> arr;
        for(int i = 0 ; i < n ; i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end(),[&](const vector<int> &a,const vector<int> &b){
            if(a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });
        long long ans = 0;
        int st = 0;
        for(int i = 0 ; i < n ; i++){
            int ind = arr[i][1];
            if(ind >= st){
                ans += S.query(0,n-1,0,st,ind);
            }else{
                ans += S.query(0,n-1,0,st,n-1)+S.query(0,n-1,0,0,ind);
            }
            st = ind;
            S.update(0,n-1,0,ind,0);
        }
        return ans;
    }
};