class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        vector<pair<int,int>> seg;
        for(int i = 0 ; i < nums1.size() ; i++) {
            seg.push_back({nums1[i],nums0[i]});
        }
        sort(seg.begin(),seg.end(),[](const auto& a, const auto& b) {
            if(a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });
       
        long long ans = 0;
        long long mod = 1e9 + 7;
        long long base = 1;
        int later = 0;
        for(int i = seg.size() - 1 ; i >= 0 ; i--) {
            auto it = seg[i];
            int ones = seg[i].first;
            int zeros = seg[i].second;
            if(zeros == 0) {
                later += ones;
                continue;
            }
            for(int l = 0 ; l < zeros ; l++) {
                base = (base * 2ll)%mod;
            }
            for(int l = 0 ; l < ones ; l++) {
                ans = (ans + base) % mod;
                base = (base * 2ll) % mod;
            }
        }
        for(int k = 0 ; k < later ; k++) {
            ans = (ans + base) % mod;
            base = (base * 2ll) % mod;
        }
        return ans%mod;
    }
};