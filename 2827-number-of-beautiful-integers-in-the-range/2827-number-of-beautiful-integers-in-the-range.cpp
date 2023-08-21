
class Solution {
public:
    int go(int n,int x,int tight,string &num,int rem,int leadingZero,int k,int dp[11][19][2][20][2]){
        int ub = (tight ? num[(num.size()-n)] - '0' : 9);
        if(n == 1){
            int ans = 0;
            if(x != 8 && x != 10) return 0;
            for(int dig = 0 ; dig <= ub ; dig++){
                int c_sum = (rem*10+dig)%k;
                if(c_sum) continue;
                int c_x = x;
                if(dig%2) c_x++;
                else c_x--;
                if(c_x != 9) continue;
                ans++;
            }
            return dp[n][x][tight][rem][leadingZero] = ans;
        }
        if(dp[n][x][tight][rem][leadingZero] != -1) return dp[n][x][tight][rem][leadingZero];
        int answer = 0;
        for(int dig = 0 ; dig <= ub ; dig++){
            int f = ( dig%2 ? 1 : ( dig ? -1 : ( leadingZero ? 0 : -1 ) ) );
            answer += go(n-1,x+f,(tight&(dig==ub)),num,(rem*10+dig)%k,leadingZero&(dig==0),k,dp);
        }
        return dp[n][x][tight][rem][leadingZero] = answer;
    }
    
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string n1 = to_string(high);
        string n2 = to_string(low-1);
        int dp[11][19][2][20][2];
        memset(dp,-1,sizeof(dp));
        int nB = go(n1.size(),9,1,n1,0,1,k,dp);
        memset(dp,-1,sizeof(dp));
        nB = nB - (low ? go(n2.size(),9,1,n2,0,1,k,dp) : 0);
        return nB;
    }
};