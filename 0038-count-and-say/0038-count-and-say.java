class Solution {
    public String countAndSay(int n) {
        if(n == 1) {
            return "1";
        }
        String smallOut = countAndSay(n-1);
        StringBuilder s = new StringBuilder();
        for(int i = 0 ; i < smallOut.length() ; ) {
            int cnt = 1;
            int j = i + 1;
            for( ; j < smallOut.length() ; j++) {
                if(smallOut.charAt(i) == smallOut.charAt(j)) {
                    cnt++;
                }else {
                    break;
                }
            }
            s.append(cnt);
            s.append(smallOut.charAt(i));
            i = j;
        }
        return s.toString();
    }
}