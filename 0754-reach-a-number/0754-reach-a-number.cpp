class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int s = 1;
        int e = 1e5;
        while(s <= e){
            long long mid = s+(e-s)/2;
            long long sum = (long long)mid*(mid+1)/2;
            if(sum < (long long)target){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        int sum = (s+1)*s/2;
        while((target-sum)%2 != 0){
            s++;
            sum = (s+1)*s/2;
        }
        return s;
    }
};