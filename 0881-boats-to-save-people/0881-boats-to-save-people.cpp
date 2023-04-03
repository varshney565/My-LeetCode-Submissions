class Solution {
public:
    int numRescueBoats(vector<int> v, int limit) {
        int s = 0;
        int e = v.size()-1;
        sort(v.begin(),v.end());
        int cnt = 0;
        while(s <= e){
            int sum1 = v[s]+v[e];
            int sum2 = v[e];
            if(sum1 <= limit){
                s++;
                e--;
            }else{
                e--;
            }
            cnt++;
        }
        return cnt;
    }
};