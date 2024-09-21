class Solution {
    List<String> ans = new ArrayList<String>();
    private void generate(int closed,int open,StringBuilder s) {
        if(open == 0 && closed == 0) {
            ans.add(s.toString());
            return;
        }
        //put one open 
        if(open > 0) {
            s.append('(');
            generate(closed,open-1,s);
            s.setLength(s.length() - 1);
        }
        //put one close
        if(closed > open) {
            s.append(')');
            generate(closed-1,open,s);
            s.setLength(s.length() - 1);
        }
    }
    
    public List<String> generateParenthesis(int n) {
        StringBuilder s = new StringBuilder();
        generate(n,n,s);
        return ans;
    }
}