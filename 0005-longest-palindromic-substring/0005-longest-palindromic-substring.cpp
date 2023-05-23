class Solution {
public:
    void manacher(string &p,vector<int> &t){
        int C = 0,R = 0;
        int n = p.size();
        for(int i = 1 ; i < n - 1 ; i++){
            int mirror = 2*C-i;
            if(i < R){
                t[i] = min(t[mirror],R-i);
            }
            while(p[i+(1+t[i])] == p[i-(1+t[i])])
                t[i]++;
            if(i+t[i] > R){
                C = i;
                R = 1+t[i];
            }
        }
    }
    
    string longestPalindrome(string s) {
        string p = "";
        p += '@';
        for(auto x : s){
            p += '#';
            p += x;
        }
        p += '#';
        p += '$';
        vector<int> t(p.size(),0);
        manacher(p,t);
        int l = 0;
        for(int i = 0 ; i < p.size() ; i++) l = max(l,t[i]);
        string ans = "";
        for(int i = 0 ; i < p.size() ; i++) {
            if(t[i] == l){
                for(int j = i-l ; j <= i+l ; j++){
                    if(p[j] != '#') ans += p[j];
                }
                return ans;
            }
        }
        return ans;
    }
};