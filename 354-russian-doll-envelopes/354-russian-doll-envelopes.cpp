class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& v) {
        int n = v.size();
        sort(v.begin(),v.end(),[](const vector<int>& a,const vector<int>& b){
            if(a[1] != b[1])
                return a[1] < b[1];
            return a[0] > b[0];
        });

        vector<int> LIS;
        for(int i = 0 ; i < n ; i++){
            auto it = lower_bound(LIS.begin(),LIS.end(),v[i][0]);
            if(it == LIS.end())
                LIS.push_back(v[i][0]);
            else
                LIS[it-LIS.begin()] = v[i][0];
        }
        return LIS.size();
    }
};