class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int i = 0;
        map<char,int> cost;
        for(auto x : vals){
            cost[chars[i]] = x;
            i++;
        }
        int ans = 0;
        int n = s.size();
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(cost.find(s[i]) != cost.end()){
                cnt += cost[s[i]];
            }else{
                cnt += (s[i]-'a')+1;
            }
            ans = max(ans,cnt);
            cnt = max(cnt,0);
        }
        ans = max(ans,cnt);
        return ans;
    }
};