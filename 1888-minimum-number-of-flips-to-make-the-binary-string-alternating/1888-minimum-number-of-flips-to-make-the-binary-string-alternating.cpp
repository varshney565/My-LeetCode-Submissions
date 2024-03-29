class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int ans = n;
        int s01 = 0,s10 = 0;
        for(int i = 0 ; i < n ; i++){
            if(i%2 == (s[i]-'0')) s10++; 
            else s01++;
        }
        /**
          * c01 and c10 is the cost to make string[0,i] in 0101 and 1010 order respectively.
          **/
        
        /**
          * s01 and s10 is the cost to make string[i+1,n-1] in 0101 and 1010 order respectively.
          **/
        
        int c01 = 0,c10 = 0;
        for(int i = 0 ; i < n ; i++){
            if((n-i)%2 == 0) ans = min(ans,min(s10+c10,s01+c01));
            else ans = min(ans,min(s10+c01,s01+c10));
            if(s[i] == '0') s10--;
            else s01--;
            swap(s10,s01);
            
            if(i%2 == 0){
                if(s[i] == '0') c10++;
                else c01++;
            }else{
                if(s[i] == '0') c01++;
                else c10++;
            }
        }
        return ans;
    }
};