class Solution {
  public:
    bool dfs(int node, int parent, vector<int> adj[], vector<bool>& visited) {
        // Mark the current node as visited
        visited[node] = true;
        
        // Traverse through all the adjacent nodes
        for (int neighbor : adj[node]) {
            // If neighbor is not visited, recursively visit it
            if (!visited[neighbor]) {
                if (dfs(neighbor, node, adj, visited)) {
                    return true;
                }
            }
            // If neighbor is visited and it's not the parent of the current node, there's a cycle
            else if (neighbor != parent) {
                return true;
            }
        }
        
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        
        // Traverse all vertices
        for (int i = 0; i < V; i++) {
            // If a vertex is not visited, apply DFS from that vertex
            if (!visited[i]) {
                if (dfs(i, -1, adj, visited)) {
                    return true;  // Cycle found
                }
            }
        }
        
        return false;
    }
};