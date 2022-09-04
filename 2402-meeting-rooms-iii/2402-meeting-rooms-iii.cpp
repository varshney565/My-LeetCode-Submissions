class Solution {
public:
    
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<int> num(n,0);
        set<pair<long long,int>> BusyRooms;
        set<int> FreeRooms;
        for(int i = 0 ; i < n ; i++){
            FreeRooms.insert(i);
        }
        
        for(int i = 0 ; i < meetings.size() ; i++){
            while(!BusyRooms.empty()){
                auto front = *BusyRooms.begin();
                if(front.first <= meetings[i][0]){
                    BusyRooms.erase(front);
                    FreeRooms.insert(front.second);
                }else{
                    break;
                }
            }
            
            if(FreeRooms.size() > 0){
                auto FreeRoom = *FreeRooms.begin();
                FreeRooms.erase(FreeRoom);
                BusyRooms.insert({meetings[i][1],FreeRoom});
                num[FreeRoom]++;
            }else{
                auto PendingNode = *BusyRooms.begin();
                BusyRooms.erase(PendingNode);
                long long delay = PendingNode.first-meetings[i][0];
                BusyRooms.insert({meetings[i][1]+delay,PendingNode.second});
                num[PendingNode.second]++;
            }
        }
        int max_ = INT_MIN;
        int room = 0;
        for(int i = 0 ; i < n ; i++){
            if(max_ < num[i]){
                max_ = num[i];
                room = i;
            }
        }
        return room;
    }
};