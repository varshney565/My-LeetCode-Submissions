class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                int len = j-i+1;
                if(len%2) continue;
                bool ok1 = true,ok2 = true;
                for(int k = i ; k < i+len/2 ; k++){
                    if(s[k] == '1') ok1 = false;
                }
                for(int k = i+len/2 ; k <= j ; k++){
                    if(s[k] == '0') ok2 = false;
                }
                if(ok1 && ok2){
                    ans = max(ans,len);
                }
            }
        }
        return ans;
    }
};