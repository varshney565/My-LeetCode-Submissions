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
        if(p1 == p2) return false;
        p[p1] = p2;
        return true;
    }
};

void MySort(vector<string> &equations){
    int n = equations.size();
    int i = 0;
    int j = n-1;
    while(i < j){
        while(i <= j && (equations[i][1] == '=')){
            i++;
        }
        while(j >= i && (equations[j][1] == '!')){
            j--;
        }
        if(i < j){
            swap(equations[i],equations[j]);
            i++;
            j--;
        }
    }
}

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        MySort(equations);
        dsu d(26);
        for(int i = 0 ; i < n ; i++){
            if(equations[i][1] == '='){
                d.unite(equations[i][0]-'a',equations[i][3]-'a');
            }else{
                int p1 = d.get(equations[i][0]-'a');
                int p2 = d.get(equations[i][3]-'a');
                if(p1 == p2) return false;
            }
        }
        return true;
    }
};