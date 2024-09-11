class Solution {
public:
    void dfs_for_components(vector<vector<int>>& adj, int u, vector<bool>& vis){
        vis[u] = true;
        
        for(auto v : adj[u]){
            if(vis[v] == false){
                dfs_for_components(adj, v, vis);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1){
            return -1;
        }

        vector<vector<int>> adj(n);
        
        for(int i = 0; i < connections.size(); i++){
            int a = connections[i][0];
            int b = connections[i][1];
            adj[a].push_back(b);    
            adj[b].push_back(a);
        }
        
        vector<bool> vis(n, false);
        int components = 0;

        for(int u = 0; u < n; u++){
            if(vis[u] == false){
                components++;
                dfs_for_components(adj, u, vis);
            }
        } 
        return components - 1;
    }
};