class Solution {
public:
    class dsu{
        public:
        vector<int> p;
        dsu(int n){
            p.resize(n);
            iota(p.begin(),p.end(),0);
        }
        int get(int n){
            if(p[n] == n){
                return n;
            }
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
    bool isSimilar(string a,string b){
        int cnt = 0;
        int n = a.size();
        for(int i = 0 ; i < n ; i++){
            if(a[i] != b[i])
                cnt++;
            if(cnt > 2)
                return false;
        }
        return true;
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int compo = n;
        dsu D(n);
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                if(isSimilar(strs[i],strs[j])){
                    if(D.unite(i,j))
                        compo--;
                }
            }
        }
        return compo;
    }
};