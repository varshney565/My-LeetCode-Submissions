class Solution {
public:
    string intToRoman(int num) {
        vector<int> values = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string> symbols = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int n = values.size();
        int i = n-1;
        string ans = "";
        while(i >= 0){
            int count = num/values[i];
            for(int j = 0 ; j < count ; j++) ans += symbols[i];
            num %= values[i];
            i--;
        }
        return ans;
    }
};