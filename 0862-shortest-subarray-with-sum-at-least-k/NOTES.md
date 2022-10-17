**point1 : **
​
let's say the sum at position i is greater than or equal to k,mean i have my answer,now i need to decrease the length.
as there can be neagitive elements so i can not decrease the length by just moving one pointer from start(because there can be a case that sum between indexes (10___2) is lesser (condition is failing) but between (10___5) is greater(condition satisfied).so i need to do something smarter.
​
.............j1(10).................j2(2).............i...............
​
if i did **sum[i]-sum[j1]**   it will give me lesser value and also maximum length
ans      **sum[i]-sum[j2]**   it will give me maximum value and minimum length
​
so it is better to take j2 insted of j1.
​
**what we can do??**
​
we need to maintain the sum that we have processed in increasing order.
mean a < b < c < d   |  sum[i]
now if sum[i]-a < k we don't need to check further because a is the smallest.
​
maintain a data structure that maintain the sum in increasing order.
(use **deque**)
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