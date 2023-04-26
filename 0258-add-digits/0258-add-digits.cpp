class Solution {
public:
    int addDigits(int num) {
        function<int(int)> go = [&](int num){
            if(num < 10) return num;
            return num%10 + go(num/10);
        };
        while(num >= 10){
            num = go(num);
        }
        return num;
    }
};