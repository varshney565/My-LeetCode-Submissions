class Solution {
public:
    class dsu{
        public : 
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
            p[p2] = p1;
            return true;
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        dsu D(n+1);
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            bool a = D.unite(edges[i][0],edges[i][1]);
            if(!a){
                ans = edges[i];
                cout<<ans[0]<<" "<<ans[1]<<"\n";
            }
        }
        return ans;
    }
};