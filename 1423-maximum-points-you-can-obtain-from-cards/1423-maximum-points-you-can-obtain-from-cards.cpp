class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for(int i = 0 ; i < k ; i++) sum += cardPoints[i];
        int last = k-1;
        int inc = n-1;
        int ans = sum;
        while(last >= 0){
            sum -= cardPoints[last];
            sum += cardPoints[inc];
            ans = max(ans,sum);
            inc--;
            last--;
        }
        return ans;
    }
};