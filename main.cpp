#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // BFS function to detect cycle
    bool bfs(int src, vector<vector<int>>& adj, vector<int>& vis) {
        queue<pair<int, int>> q;
        vis[src] = 1;
        q.push({src, -1}); // {current_node, parent_node}

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto neighbor : adj[node]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = 1;
                    q.push({neighbor, node});
                } 
                else if (neighbor != parent) {
                    // Node is already visited and not parent ⇒ cycle
                    return true;
                }
            }
        }

        return false; // no cycle in this component
    }

public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> vis(V, 0);

        // Step 1: Build adjacency list from edge list
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected graph
        }

        // Step 2: Handle disconnected components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (bfs(i, adj, vis)) {
                    return true; // cycle found
                }
            }
        }

        return false; // no cycles in any component
    }
};

int main() {
    Solution sol;

    int V = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 1} // This creates a cycle
    };

    if (sol.isCycle(V, edges))
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle found" << endl;

    return 0;
}
