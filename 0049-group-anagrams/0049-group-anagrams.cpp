class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> st;
        for(auto x : strs){
            string t = x;
            sort(t.begin(),t.end());
            st[t].push_back(x);
        }
        vector<vector<string>> ans;
        for(auto [t,x] : st){
            ans.push_back({});
            for(auto v : x){
                ans.back().push_back(v);
            }
        }
        return ans;
    }
};