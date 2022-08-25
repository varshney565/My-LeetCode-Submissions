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
    int unite(int a,int b){
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        dsu D(n);
        for(int i = 0 ; i < pairs.size() ; i++){
            D.unite(pairs[i][0],pairs[i][1]);
        }
        map<int,multiset<int>> F;
        for(int i = 0 ; i < n ; i++){
            int p = D.get(i);
            F[p].insert(s[i]);
        }
        string ans = "";
        for(int i = 0 ; i < n ; i++){
            int p = D.get(i);
            ans += *(F[p].begin());
            F[p].erase(F[p].begin());
        }
        return ans;
    }
};