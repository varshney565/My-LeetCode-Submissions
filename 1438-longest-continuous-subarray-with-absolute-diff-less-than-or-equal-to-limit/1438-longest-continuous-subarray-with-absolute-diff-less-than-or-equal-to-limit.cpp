class MinSegTree{
    public:
    vector<int> arr;
    vector<int> Seg;
    int n;
    MinSegTree(vector<int> &v){
        arr.insert(arr.end(),v.begin(),v.end());
        Seg.resize(4*arr.size(),0);
        n = arr.size();
    }
    
    void build(int high,int low = 0,int ind = 0){
        if(low == high){
            Seg[ind] = arr[low];
            return;
        }
        int mid = (low+high)/2;
        build(mid,low,2*ind+1);
        build(high,mid+1,2*ind+2);
        Seg[ind] = min(Seg[2*ind+1],Seg[2*ind+2]);
    }
    
    int query(int l,int r,int low,int high,int ind){
        if(low > r || l > high){
            return INT_MAX;
        }
        if(low >= l && high <= r){
            return Seg[ind];
        }
        int mid = (low+high)/2;
        int left = query(l,r,low,mid,2*ind+1);
        int right = query(l,r,mid+1,high,2*ind+2);
        return min(left,right);
    }
};

class MaxSegTree{
    public:
    vector<int> arr;
    vector<int> Seg;
    int n;
    MaxSegTree(vector<int> &v){
        arr.insert(arr.end(),v.begin(),v.end());
        Seg.resize(4*arr.size(),0);
        n = arr.size();
    }
    
    void build(int high,int low = 0,int ind = 0){
        if(low == high){
            Seg[ind] = arr[low];
            return;
        }
        int mid = (low+high)/2;
        build(mid,low,2*ind+1);
        build(high,mid+1,2*ind+2);
        Seg[ind] = max(Seg[2*ind+1],Seg[2*ind+2]);
    }
    
    int query(int l,int r,int low,int high,int ind){
        if(low > r || l > high){
            return INT_MIN;
        }
        if(low >= l && high <= r){
            return Seg[ind];
        }
        int mid = (low+high)/2;
        int left = query(l,r,low,mid,2*ind+1);
        int right = query(l,r,mid+1,high,2*ind+2);
        return max(left,right);
    }
};


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        MinSegTree S1(nums);
        MaxSegTree S2(nums);
        S1.build(n-1);S2.build(n-1);
        //build(n-1)
        //query(l,r,0,n-1,0)
        int i = 0,j = 0;
        int ans = 0;
        while(j < n){
            int min_ = S1.query(i,j,0,n-1,0);
            int max_ = S2.query(i,j,0,n-1,0);
            while(max_ - min_ > limit){
                i++;
                max_ = S2.query(i,j,0,n-1,0);
                min_ = S1.query(i,j,0,n-1,0);
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};