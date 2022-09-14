class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& v) {
        int n = v.size();
        sort(v.begin(),v.end(),[](const vector<int>& a,const vector<int>& b){
            if(a[1] != b[1])
                return a[1] < b[1];
            return a[0] > b[0];
        });

        vector<vector<int>> LIS;
        for(int i = 0 ; i < n ; i++){
            int si = 0;
            int ei = LIS.size()-1;
            while(si <= ei){
                int mid = (si+ei)/2;
                if(LIS[mid][0] < v[i][0] && LIS[mid][1] < v[i][1]){
                    si = mid+1;
                }else{
                    ei = mid-1;
                }
            }
            if(si == LIS.size()){
                LIS.push_back(v[i]);
            }else{
                LIS[si] = v[i];
            }
        }
        return LIS.size();
    }
};