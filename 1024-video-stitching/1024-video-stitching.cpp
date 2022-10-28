class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size();
        sort(clips.begin(),clips.end(),[&](vector<int>&a,vector<int>&b){
            if(a[0] != b[0]) return a[0] < b[0];
            return a[0]-a[1] < b[0]-b[1];
        });
        
        if(clips[0][0] != 0) return -1;
        int cnt = 1;
        int i = 1;
        int curr = 0;
        int next = -1;
        while(i < n){
            if(clips[curr][1] >= time)
                break;
            if(clips[i][0] > clips[curr][1]){
                if(next == -1) return -1;
                curr = next;
                next = -1;
                cnt++;
                continue;
            }
            if(clips[i][1] > clips[curr][1]){
                if(next == -1) next = i;
                else if(clips[next][1] < clips[i][1]) next = i;
            }
            i++;
        }
        if(next != -1) cnt++,curr = next;
        if(clips[curr][1] < time) return -1;
        return cnt;
    }
};