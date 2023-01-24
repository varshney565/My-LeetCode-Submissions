class MinStack {
public:
    stack<long long> st;
    long long minEle;
    MinStack() : minEle(-1){
        //done
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minEle = val;
            return;
        }
        
        if(val < minEle){
            st.push(2ll*val-(long long)minEle);
            minEle = val;
        }else{
            st.push(val);
        }
    }
    
    void pop() {
        if(st.top() < minEle){
            minEle = 2ll*minEle-st.top();
        }
        st.pop();
    }
    
    int top() {
        if(minEle <= st.top())
            return st.top();
        return minEle;
    }
    
    int getMin() {
        return minEle;
    }
};