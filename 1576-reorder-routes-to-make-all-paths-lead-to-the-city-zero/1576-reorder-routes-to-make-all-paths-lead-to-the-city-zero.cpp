class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        vector<vector<pair<int, bool>>> adjList(n);
        
        // Create the adjacency list with direction information
        for (const auto& conn : connections) {
            adjList[conn[0]].emplace_back(conn[1], true);  // original direction
            adjList[conn[1]].emplace_back(conn[0], false); // reverse direction
        }
        
        // BFS initialization
        queue<int> q;
        vector<bool> visited(n, false);
        int changes = 0;
        
        // Start BFS from node 0
        q.push(0);
        visited[0] = true;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (const auto& [neighbor, isOriginal] : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                    if (isOriginal) {
                        changes++; // Count the edge that needs to be reversed
                    }
                }
            }
        }
        return changes;
    }
};