class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        set<string> dict;
        for(auto x : wordDict) dict.insert(x);
        vector<int> ansExist(n+1,-1);
        function<int(int)> go = [&](int n){
            if(n == 0) return ansExist[n] = 1;
            if(ansExist[n] != -1) return ansExist[n];
            string tmp = "";
            bool ans = false;
            for(int i = n - 1 ; i >= 0 ; i--){
                tmp = s[i] + tmp;
                if(dict.find(tmp) != dict.end()){
                    ans = go(i) || ans;
                }
            }
            return ansExist[n] = (ans?1:0);
        };
        go(n);
        function<vector<string>(int)> yes = [&](int n){
            vector<string> ans;
            for(int i = n - 1 ; i >= 0 ; i--){
                if(ansExist[i] == 1 && dict.find(s.substr(i,n-i)) != dict.end()){
                    string p = s.substr(i,n-i);
                    if(i){
                        auto smallAns = yes(i);
                        for(auto t : smallAns){
                            ans.push_back(t+" "+p);
                        }
                    }else{
                        ans.push_back(p);
                    }
                }
            }
            return ans;
        };
        return yes(n);
    }
};