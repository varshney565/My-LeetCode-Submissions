class Solution {
public:
    
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
};