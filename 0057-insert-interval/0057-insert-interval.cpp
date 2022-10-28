class Solution {
public:
    
    vector<vector<int>> mergeOverlappingInterval(vector<vector<int>>& intervals){
        int n = intervals.size();
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 1 ; i < n ; i++){
            if(intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }else{
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        //insert the newInterval in intetval array at its correct place.
        int i;
        for(i = 0 ; i < n ; i++){
            if(newInterval[0] <= intervals[i][0]){
                intervals.insert(intervals.begin()+i,newInterval);
                break;
            }
        }
        if(i == n)
            intervals.push_back(newInterval);
        return mergeOverlappingInterval(intervals);
    }
};