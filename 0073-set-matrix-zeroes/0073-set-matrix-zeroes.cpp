class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(n,false);
        vector<bool> col(m,false);
        //if mat[i][j] = 0 set all the values in row i and col j as 0
        
        //find all such rows and columns such that they needed to be set as 0
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!matrix[i][j]) row[i] = true,col[j] = true;
            }
        }
        //setting rows and columns as 0.
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(row[i] || col[j]) matrix[i][j] = 0;
            }
        }
    }
};