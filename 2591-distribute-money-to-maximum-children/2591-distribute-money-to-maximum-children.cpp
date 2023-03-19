class Solution {
public:
    int distMoney(int money, int children) {
        if(children > money) return -1;
        if(8*children < money){
            return children-1;
        }
        if(8*children == money) return children;
        money = money-children;
        if(7*(children-1) < money){
            int r = money%7;
            if(r == 3)
                return children-2;
            return children-1;
        }
        return money/7;
    }
};