class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> cnt(10,0);
        while(n){
            int r = n%10;
            cnt[r]++;
            n = n/10;
        }
        for(int i = 0 ; i <= 30 ; i++){
            vector<int> cnt1(10,0);
            int n = pow(2,i);
            while(n){
                cnt1[n%10]++;
                n = n/10;
            }
            int j;
            for(j = 0 ; j < 10 ; j++){
                if(cnt[j] != cnt1[j])
                    break;
            }
            if(j == 10)
                return true;
        }
        return false;
    }
};