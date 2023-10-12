class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        int m = people.size();
        vector<pair<int,int>> people_index;
        for(int i = 0 ; i < m ; i++) {
            people_index.push_back({people[i],i});
        }
        sort(people_index.begin(),people_index.end(),[](const pair<int,int> &a, const pair<int,int> &b) {
            if(a.first != b.first) {
                return a.first < b.first;
            }
            return a.second < b.second;
        });

        vector<int> f1,f2;
        for(int i = 0 ; i < n ; i++) {
            f1.push_back(flowers[i][0]);
            f2.push_back(flowers[i][1]);
        }
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());
        vector<int> ans(m,0);
        int t1 = 0,t2 = 0;
        int total_flowers = 0;
        for(int i = 0 ; i < m ; i++) {
            while(t1 < n && f1[t1] <= people_index[i].first) {
                total_flowers++;
                t1++;
            }
            while(t2 < n && f2[t2] < people_index[i].first) {
                total_flowers--;
                t2++;
            }
            ans[people_index[i].second] = total_flowers;
        }
        return ans;
    }
};