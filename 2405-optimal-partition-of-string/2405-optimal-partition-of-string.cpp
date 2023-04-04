class Solution {
public:
    int partitionString(string s) {
        set<char> yes;
        int ans = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(yes.find(s[i]) != yes.end()){
                yes.clear();
                ans++;
            }
            yes.insert(s[i]);
        }
        return ans+1;
    }
};