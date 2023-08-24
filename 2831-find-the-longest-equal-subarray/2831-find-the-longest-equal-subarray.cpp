class Solution {
public:
    int longestEqualSubarray(vector<int>& A, int k) {
        int maxf = 0, i = 0, n = A.size();
        map<int, int> count;
        for (int j = 0; j < n; j++) {
            maxf = max(maxf, ++count[A[j]]);
            if (j - i + 1 - maxf > k)
                --count[A[i++]];
        }
        return maxf;
    }
};