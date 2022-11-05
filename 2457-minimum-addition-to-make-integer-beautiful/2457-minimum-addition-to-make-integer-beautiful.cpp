class Solution {
public:
    long long sum(long long n){
        if(n <= 9) return n;
        return n%10+sum(n/10);
    }
    
    long long makeIntegerBeautiful(long long n, int target) {
        long long addition = 0;
        long long times = 1;
        while(n > 1){
            long long s = sum(n);
            if(s <= target)
                return addition;
            addition += (10-(n%10))*times;
            n += 10-n%10;
            times *= 10;
            n = n/10;
        }
        return addition;
    }
};