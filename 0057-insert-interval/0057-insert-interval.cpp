class Solution {
public:    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int i = 0;
        //check till what point the newInterval is not overlapping
        while(i < intervals.size() && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        //merge the newInterval with the intervals that are overlapping
        while(i < intervals.size() && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0],intervals[i][0]);
            newInterval[1] = max(newInterval[1],intervals[i][1]);
            i++;
        }
        //insert the newly interval
        ans.push_back(newInterval);
        //insert the remaining intervals
        while(i < intervals.size()){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};