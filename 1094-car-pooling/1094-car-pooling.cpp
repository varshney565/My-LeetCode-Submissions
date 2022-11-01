class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<int> pre(1005,0);
        for(int i = 0 ; i < n ; i++){
            pre[trips[i][1]] += trips[i][0];
            pre[trips[i][2]] -= trips[i][0];
        }
        for(int i = 0 ; i < 1005 ; i++){
            if(i) pre[i] += pre[i-1];
            if(pre[i] > capacity) return false;
        }
        return true;
    }
};