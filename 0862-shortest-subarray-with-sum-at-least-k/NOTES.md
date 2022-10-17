​
**point2 : **
​
p1.............p2.......p3.....
​
when i reach p2 and p2-p1 >= k then i am removing p1.why??
because if p2-p1 >= k and later p3-p1 >= k but i want the minimum length so i can remove p1,because it is giving me the least distance.
​
​
**point 3:**
neagitive elements can be there at the front of dequeue,that's why we have to remove the elements from the front of the queue irrespective of the sum is greater than k or not because there can be a case such that sum is not greater than k but excluding the front element of the queue making the sum greater than k.
​
​
**point 4 :**
use array of long long.
​
```
class Solution {
public:
int shortestSubarray(vector<int>& A, int k) {
int n = A.size();
int ans = n+1;
vector<long long> nums(n);
deque<int> Pre;
for(int i = 0 ; i < n ; i++){
nums[i] = A[i];
if(i) nums[i] += nums[i-1];
//if sum if greater than or equal to answer mean we found the answer.
if(nums[i] >= k){
ans = min(ans,i+1);
}
//neagitive elements can be there at the front of dequeue
//that's why we have to remove the elements from the front of the queue irrespective of
//the sum is greater than k or not because there can be a case such that sum is not greater than
//k but excluding the front element of the queue making the sum greater than k.
while(!Pre.empty() && nums[i] - nums[Pre.front()] >= k){
ans = min(ans,i-Pre.front());
Pre.pop_front();
}
//find where to insert the current sum till position i.
while(!Pre.empty() && nums[Pre.back()] >= nums[i]){
Pre.pop_back();
}
//insert the sum into the stack.
Pre.push_back(i);
}
return (ans == n+1)?-1:ans;
}
};
```