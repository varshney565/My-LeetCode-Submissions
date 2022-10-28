class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        /**
        
        0 --> [-3,3]
        1 --> [-3,5]
        2 --> [1,3]
        3 --> [2,4]
        4 --> [4,4]
        5 --> [5,5]
        
        */
        
        vector<vector<int>> interval;
        for(int i = 0 ; i < ranges.size() ; i++){
            interval.push_back({max(0,i-ranges[i]),min(n,i+ranges[i])});
        }
        /**
        club the gap of [0,n] by taking minimum number of intervals 
        */
        
        sort(interval.begin(),interval.end(),[&](vector<int>&a,vector<int>&b){
            if(a[0] != b[0])
                return a[0] < b[0];
            return a[1]-a[0] > b[1]-b[0];
        });
        
        if(interval[0][0] != 0) return -1;
        int curr = 0;
        int next = -1;
        int i = 1;
        int cnt = 1;
        while(i < interval.size()){
            if(interval[curr][1] < interval[i][0]){
                if(next == -1) return -1;
                curr = next;
                next = -1;
                cnt++;
                continue;
            }
            
            if(interval[i][1] > interval[curr][1]){
                if(next == -1) next = i;
                else if(interval[next][1] < interval[i][1]){
                    next = i;
                }
            }
            i++;
        }
        if(next != -1) cnt++;
        return cnt;
    }
};