#define MOUSE_TURN 0
#define CAT_TURN 1
#define MOUSE 1
#define CAT 2
#define DRAW 0
class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        //calculating the dependencies of the given Graph ...
        vector<vector<vector<int>>> dep(n,vector<vector<int>>(n,vector<int>(2,0)));
        vector<vector<vector<int>>> Winner(n,vector<vector<int>>(n,vector<int>(2,0)));
        for(int mouse = 0 ; mouse < n ; mouse++){
            for(int cat = 0 ; cat < n ; cat++){
                dep[mouse][cat][MOUSE_TURN] = graph[mouse].size();
                dep[mouse][cat][CAT_TURN] = graph[cat].size();
                for(auto x : graph[cat]){
                    if(x == 0){
                        dep[mouse][cat][CAT_TURN]--;
                        break;
                    }
                }
            }
        }
        
        //Handling the Known winning and losing states ...
        queue<vector<int>> KnownStates;
        //mouse_pos,cat_pos,turn,Status
        for(int i = 0 ; i < n ; i++){
            for(int turn = 0 ; turn < 2 ; turn++){
                KnownStates.push({0,i,turn,MOUSE});
                Winner[0][i][turn] = MOUSE;
                if(i > 0){
                    KnownStates.push({i,i,turn,CAT});
                    Winner[i][i][turn] = CAT;
                }
            }
        }
        
        while(!KnownStates.empty()){
            auto front = KnownStates.front();
            KnownStates.pop();
            int m = front[0];
            int c = front[1];
            int t = front[2];
            int w = front[3];
            if(t == MOUSE_TURN){
                int t2 = CAT_TURN;
                if(w == CAT){
                    for(auto c2 : graph[c]){
                        if(c2 == 0) continue;
                        if(!Winner[m][c2][t2]){
                            Winner[m][c2][t2] = CAT;
                            KnownStates.push({m,c2,t2,CAT});
                        }
                    }
                }else{
                    for(auto c2 : graph[c]){
                        if(c2 == 0) continue;
                        if(Winner[m][c2][t2])
                            continue;
                        dep[m][c2][t2]--;
                        if(dep[m][c2][t2] == 0){
                            Winner[m][c2][t2] = MOUSE;
                            KnownStates.push({m,c2,t2,MOUSE});
                        }
                    }
                }
            }else{//CAT_TURN
                int t2 = MOUSE_TURN;
                if(w == MOUSE){
                    for(auto m2 : graph[m]){
                        if(!Winner[m2][c][t2]){
                            Winner[m2][c][t2] = MOUSE;
                            KnownStates.push({m2,c,t2,MOUSE});
                        }
                    }
                }else{
                    for(auto m2 : graph[m]){
                        if(Winner[m2][c][t2])
                            continue;
                        dep[m2][c][t2]--;
                        if(dep[m2][c][t2] == 0){
                            Winner[m2][c][t2] = CAT;
                            KnownStates.push({m2,c,t2,CAT});
                        }
                    }
                }
            }
        }
        return Winner[MOUSE][CAT][MOUSE_TURN];
    }
};