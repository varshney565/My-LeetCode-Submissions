class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string,int> cnt;
        map<string,int> Max;
        map<string,int> Id;
        int n = creators.size();
        for(int i = 0 ; i < n ; i++){
            if(Max[creators[i]] < views[i]){
                Max[creators[i]] = views[i];
                Id[creators[i]] = i;
            }else if(Max[creators[i]] == views[i]){
                if(Id.find(creators[i]) == Id.end() || ids[Id[creators[i]]] > ids[i]){
                    Id[creators[i]] = i;
                }
            }
        }

        int max_ = INT_MIN;

        for(int i = 0 ; i < n ; i++){
            cnt[creators[i]] += views[i];
            if(cnt[creators[i]] > max_){
                max_ = cnt[creators[i]];
            }
        }

        vector<vector<string>> ans;
        for(auto &[a,x] : cnt){
            if(x == max_)
                ans.push_back({a,ids[Id[a]]});
        }
        return ans;
    }
};