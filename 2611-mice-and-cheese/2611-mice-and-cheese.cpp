class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<pair<int,int>> t;
        for(int i = 0 ; i < n ; i++){
            t.push_back({reward1[i],reward2[i]});
        }
        sort(t.begin(),t.end(),[&](const pair<int,int> &a,const pair<int,int> &b){
            int dif1 = a.first-a.second;
            int dif2 = b.first-b.second;
            return dif1 > dif2;
        });
        // for(int i = 0 ; i < n ; i++) cout<<t[i].first << " " << t[i].second << "\n";
        int ans = 0;
        for(int i = 0 ; i < k ; i++){
            ans += t[i].first;
        }
        for(int i = k ; i < n ; i++){
            ans += t[i].second;
        }
        return ans;
    }
};