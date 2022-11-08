class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
        // find the upper bound and lower bound of x and start from there.
        sort(arr.begin(),arr.end());
        int s = 0,e = n-1;
        while(s <= e){
            int mid = (s+e)/2;
            if(arr[mid] > x) e = mid-1;
            else s = mid+1;
        }
        //now s is pointing to upper_bound of x in arr.
        while(s < n && e >= 0 && ans.size() < k){
            int val1 = abs(arr[s]-x);
            int val2 = abs(arr[e]-x);
            if(val1 < val2){
                ans.push_back(arr[s]);
                s++;
            }else if(val2 < val1){
                ans.push_back(arr[e]);
                e--;
            }else{
                if(arr[s] < arr[e]){
                    ans.push_back(arr[s]);
                    s++;
                }else{
                    ans.push_back(arr[e]);
                    e--;
                }
            }
        }
        while(s < n && ans.size() < k){
            ans.push_back(arr[s]);
            s++;
        }
        while(e >= 0 && ans.size() < k){
            ans.push_back(arr[e]);
            e--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};