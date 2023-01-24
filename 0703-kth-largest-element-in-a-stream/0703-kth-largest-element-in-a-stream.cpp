/**
 *  use two priority queues.
 * 
 *  first ----> min heap but it can have at max k elements
 * 
 *  second ---> max heap
 * 
 *  k = 3
 *  [4,5,8,2]
 *  
 *  add(3,5,10,9,4)
 *  
 *  first 4 5 8
 *  second 2
 * 
 *  add(3)
 *  first 4 5 8
 *  second 2 3
 * 
 *  add(5)
 *  first 5 5 8
 *  second 2 3 4
 * 
 * */


class KthLargest {
public:
    int k;
    priority_queue<int> pq1; //max
    priority_queue<int,vector<int>,greater<int>> pq2; //min
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i = 0 ; i < nums.size() ; i++){
            this->add(nums[i]);
        }
    }
    
    int add(int val) {
        if(pq2.size() < k)
            pq2.push(val);
        else{
            int vtop = pq2.top();
            if(vtop >= val){
                pq1.push(val);
            }else{
                pq2.pop();
                pq1.push(vtop);
                pq2.push(val);
            }
        }
        return pq2.top();
    }
};