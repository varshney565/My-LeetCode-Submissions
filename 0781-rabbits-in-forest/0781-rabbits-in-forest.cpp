class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        int ans = 0;
        map<int,int> cnt;
        for(auto &x : answers)
            cnt[x]++;
        
        for(auto &[a,b] : cnt){
            if(b%(a+1) == 0)
                ans += b;
            else
                ans += b-b%(a+1)+a+1;
        }
        return ans;
    }
};