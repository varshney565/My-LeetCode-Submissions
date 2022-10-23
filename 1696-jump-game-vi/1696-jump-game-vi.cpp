class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        // int n = nums.size();
        // deque<pair<int,int>> d;
        // int i = 0;
        // while(i < n){
        //     //erase all the elements that needed to be deleted.
        //     while(!d.empty() && d.front().first < i-k)
        //         d.pop_front();
        //     //do the processing.
        //     int max_ = (d.empty()?0:d.front().second)+nums[i];
        //     //insert all the needed elements.
        //     while(!d.empty() && d.back().second < max_)
        //         d.pop_back();
        //     d.push_back({i,max_});
        //     i++;
        // }
        // return d.back().second;
        
        
        int minJump = 1;
        int maxJump = k;
        int n = nums.size();
        int i = minJump;
        map<int,int> processedElements;
        deque<pair<int,int>> d;
        processedElements.insert({0,nums[0]});
        while(i < n){
            //insert the needy elements
            int eleInd = i-minJump;
            if(processedElements.find(eleInd) != processedElements.end()){
                while(!d.empty() && d.back().second < processedElements[eleInd])
                    d.pop_back();
                d.push_back({eleInd,processedElements[eleInd]});
            }
            //remove the element 
            while(!d.empty() && d.front().first < i-maxJump)
                d.pop_front();
            //Actutal processing 
            int max_ = (d.empty()?0:d.front().second)+nums[i];
            processedElements.insert({i,max_});
            i++;
        }
        return (processedElements.find(n-1) != processedElements.end())?processedElements[n-1]:-1;
    }
};