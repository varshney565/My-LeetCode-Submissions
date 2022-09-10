int max(int a,int b){
    return a>b?a:b;
}
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        set<string> Words;
        int l = 0;
        for(auto x : wordDict){
            Words.insert(x);
            l = max(l,x.size());
        }
        
        vector<bool> dp(n+1,false);
        dp[0] = true;
        for(int i = 0 ; i <= n ; i++){
            if(!dp[i]) continue;
            string tmp = "";
            for(int j = i + 1 ; j <= n && j <= i + l ; j++){
                tmp += s[j-1];
                if(Words.find(tmp) != Words.end()){
                    dp[j] = true;
                }
            }
        }
        return dp[n];
    }
};