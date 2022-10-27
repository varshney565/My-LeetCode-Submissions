class Solution {
public:
    int maxAbsValExpr(vector<int>& a, vector<int>& b) {
        /**
            eq = | a[i]-a[j] | + | b[i] -b[j] | + | i-j |
            
               = (ai-aj)+(bi-bj)+(i-j) =  (ai+bi+i)-(aj+bj+j)
               = -(ai-aj)+(bi-bj)+(i-j) = (bi-ai+i)-(bj-aj+j)
               = (ai-aj)-(bi-bj)+(i-j) =  (ai-bi+i)-(aj-bj+j)
               = -(ai-aj)-(bi-bj)+(i-j) = (-ai-bi+i)-(-aj-bj+j)
        */
        int Min[4] = {INT_MAX,INT_MAX,INT_MAX,INT_MAX};
        int Max[4] = {INT_MIN,INT_MIN,INT_MIN,INT_MIN};
        int sign[4][2] = {{1,1},{-1,1},{1,-1},{-1,-1}};
        for(int j = 0 ; j < a.size() ; j++){
            for(int i = 0 ; i < 4 ; i++){
                int val = sign[i][0]*a[j]+sign[i][1]*b[j]+j;
                Min[i] = min(Min[i],val);
                Max[i] = max(Max[i],val);
            }
        }
        int ans = INT_MIN;
        for(int i = 0 ; i < 4 ; i++){
            ans = max(ans,Max[i]-Min[i]);
        }
        return ans;
    }
};