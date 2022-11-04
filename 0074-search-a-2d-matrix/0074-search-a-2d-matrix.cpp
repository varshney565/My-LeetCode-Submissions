class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /**
        What Question demands ??
        find the lower_bound of target_row assumng the first column to be sorted in decreasing order.
        **/
        
        int n = matrix.size();
        int m = matrix[0].size();
        int s = 0;
        int e = n-1;
        while(s <= e){
            int mid = s+(e-s)/2;
            if(matrix[mid][0] > target){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        //now e will have the access to the element that we needed.
        //because [row no : e + 1] will gonna start from [target + k,...........so on]
        int r = e;
        if(r < 0) return false;
        s = 0;
        e = m-1;
        //now search in row for the target.
        //if found return true else return false.
        while(s <= e){
            int mid = s+(e-s)/2;
            if(matrix[r][mid] > target){
                e = mid-1;
            }else if(matrix[r][mid] < target){
                s = mid+1;
            }else{
                return true;
            }
        }
        return false;
    }
};