class Solution {
public:
    bool detect_cycle(unordered_map<int,list<int>> adj,vector<int> &visited,int node,int parent){
        visited[node]=1;
        for(auto adjacent_node:adj[node]){
            if(!visited[adjacent_node]){
                if(detect_cycle(adj,visited,adjacent_node,node)){
                    return true;
                }
            }
            else{
                if(adjacent_node!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<int>> adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n,0);
        int components=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                components++;
                if(detect_cycle(adj,visited,i,-1)){
                    return false;
                }
            } 
        }
        if(components>1){
            return false;
        }
        return true;
    }
};
