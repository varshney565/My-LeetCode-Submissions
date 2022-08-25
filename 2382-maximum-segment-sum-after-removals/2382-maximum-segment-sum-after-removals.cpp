class dsu{
    public:
    vector<int> p;
    vector<long long> v;
    dsu(int n,vector<int> &nums){
        v.insert(v.end(),nums.begin(),nums.end());
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
        if(p1 == p2) return false;
        p[p1] = p2;
        v[p2] += v[p1];
        return true;
    }
};

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int m = removeQueries.size();
        int n = nums.size();
        vector<bool> visited(n,false);
        dsu D(n,nums);
        set<long long,greater<long long>> F;
        vector<long long> ans;
        ans.push_back(0);
        for(int i = m-1 ; i > 0 ; i--){
            int ind = removeQueries[i];
            if(ind-1 >= 0 && visited[ind-1]){
                D.unite(ind-1,ind);
            }
            if(ind+1 < n && visited[ind+1]){
                D.unite(ind+1,ind);
            }
            F.insert(D.v[D.get(ind)]);
            ans.push_back(*F.begin());
            visited[ind] = true;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};