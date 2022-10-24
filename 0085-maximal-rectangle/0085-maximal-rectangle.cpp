class Solution {
public:
    /**
    It's a n*n*n solution 
    */
    int findMaxArea(vector<bool>&yes){
        //return the maximum number of true in the yes array,
        int ans = 0;
        int cnt = 0;
        int n = yes.size();
        for(int i = 0 ; i < n ; i++){
            if(yes[i]) cnt++;
            else cnt = 0;
            ans = max(cnt,ans);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            vector<bool> yes(m,true);
            for(int j = i ; j < n ; j++){
                for(int k = 0 ; k < m ; k++){
                    yes[k] = (yes[k]&(matrix[j][k]-'0'));
                }
                ans = max(ans,(j-i+1)*findMaxArea(yes));
            }
        }
        return ans;
    }
    /**
    
    we can do this problem using stack in n*n time. how??
    largest rectanguler area in the hostogram technique.
    will do it later when stack comes....
    
    
    
    but the logic will be as follows....
    for(int i = 0 ; i < n ; i++){
        if(i)
            mat[i][j] += mat[i-1][j];
        find the previous smaller and next smaller element for each element of mat[i] and find the             area and compare it with max
    }
    return max;
    */
};