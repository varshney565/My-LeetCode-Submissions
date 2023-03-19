class Solution {
public:    
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        long long s = 1;
        long long e = 1e14+10;
        while(s <= e){
            long long mid = (s+e)/2;
            //check whether cars can be replared in time mid or not 
            long long done = 0;
            for(int i = 0 ; i < n ; i++){
                int val = sqrt(mid/ranks[i]);
                done += val;
                if(done >= cars){
                    break;
                }
            }
            
            if(done >= cars){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return s;
    }
};