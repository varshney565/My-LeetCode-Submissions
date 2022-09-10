class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        set<string> Words;
        for(auto x : wordDict){
            Words.insert(x);
        }
        function<vector<string>(int)> go = [&](int n){
            if(n == 0){
                vector<string> v;
                v.push_back("");
                return v;
            }
            string tmp = "";
            vector<string> ans;
            for(int i = n-1 ; i >= 0 ; i--){
                tmp = s[i]+tmp;
                if(Words.find(tmp) != Words.end()){
                    auto SmallAns = go(i);
                    for(auto x : SmallAns){
                        if(x == "")
                            ans.push_back(tmp);
                        else
                            ans.push_back(x+" "+tmp);
                    }
                }
            }
            return ans;
        };
        return go(n);
    }
};