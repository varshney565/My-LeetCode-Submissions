class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        int i = minJump;
        set<int> isAnswerExist;
        deque<int> d;
        isAnswerExist.insert(0);
        while(i < n){
            //remove the element from window.
            while(!d.empty() && d.front() < i-maxJump)
                d.pop_front();
            //insert the element from the window.
            if(isAnswerExist.find(i-minJump) != isAnswerExist.end()){
                d.push_back(i-minJump);
            }
            //process the current state
            if(d.size() > 0 && s[i] == '0')
                isAnswerExist.insert(i);
            i++;
        }
        return (isAnswerExist.find(n-1)!=isAnswerExist.end())?true:false;
    }
};