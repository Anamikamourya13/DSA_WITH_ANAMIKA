class Solution {
public:
    vector<bool>visited;
    void dfs(int room, vector<vector<int>>& rooms){
        visited[room] = true;  // current rooms visit

        for(int key : rooms[room]){
            if(visited[key]== false){
                dfs(key, rooms);  //keys s enew room 
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms){
        int n= rooms.size();
        visited = vector<bool>(n, false);
        dfs(0, rooms); //room 0 se start
        for(int i=0; i<n; i++){
            if(visited[i] == false)
             return false;
        }
    
    return true;
    }
};