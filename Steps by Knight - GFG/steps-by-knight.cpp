//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n){
	    KnightPos[0]--;KnightPos[1]--;TargetPos[0]--;TargetPos[1]--;
	    int dir[][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
	    queue<int> PendingNodes;
	    PendingNodes.push(KnightPos[0]*n+KnightPos[1]);
	    int level = 0;
	    vector<vector<bool>> visited(n,vector<bool>(n,false));
	    visited[KnightPos[0]][KnightPos[1]] = true;
	    while(!PendingNodes.empty()){
	        int size = PendingNodes.size();
	        while(size-->0){
	            int frontNode = PendingNodes.front();
	            PendingNodes.pop();
	            int x = frontNode/n;
	            int y = frontNode%n;
	            if(x == TargetPos[0] && y == TargetPos[1]) return level;
	            for(int i = 0 ; i < 8 ; i++){
	                int newx = x+dir[i][0];
	                int newy = y+dir[i][1];
	                if(newx >= 0 && newx < n && newy >= 0 && newy < n && !visited[newx][newy]){
	                    PendingNodes.push(newx*n+newy);
	                    visited[newx][newy] = true;
	                }
	            }
	        }
	        level++;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends