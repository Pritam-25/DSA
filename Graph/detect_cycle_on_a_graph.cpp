#include <bits/stdc++.h>
using namespace std;

//* dfs
class Solution {
public:
    // DFS helper to detect cycle in an undirected graph
    bool dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &adjLs) {
        vis[node] = 1;  // mark current node as visited

        for (auto adjNode : adjLs[node]) {
            if (!vis[adjNode]) {
                // recurse on unvisited neighbor
                if (dfs(adjNode, node, vis, adjLs)) {
                    return true;
                    // if any path returns true, cycle is found, 
                    // return immediately, no need to check further
                }
            }
            // if visited neighbor is not the parent => cycle found
            else if (adjNode != parent) {
                return true;
            }
        }

        return false;  // no cycle found in this path
    }

    // Main function to check for cycle in undirected graph
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Step 1: Convert edge list to adjacency list
        vector<vector<int>> adjLs(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjLs[u].push_back(v);
            adjLs[v].push_back(u);  // undirected graph
        }

        // Step 2: Initialize visited array
        vector<int> vis(V, 0);

        // Step 3: Run DFS for all disconnected components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, vis, adjLs)) return true;  // cycle found
            }
        }

        return false;  // no cycles in any component
    }
};



//* bfs
class Solution {
public:
    // Step 2: BFS function to detect cycle starting from `src`
    bool detect(int src, vector<int> &vis, vector<vector<int>> &adj) {
        vis[src] = 1;  // mark the starting node as visited
        queue<pair<int, int>> q;
        q.push({src, -1});  // push (node, parent)

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            // Traverse all adjacent nodes
            for (auto adjNode : adj[node]) {
                if (!vis[adjNode]) {
                    vis[adjNode] = 1;
                    q.push({adjNode, node});
                }
                // If visited and not parent, cycle is found
                else if (adjNode != parent) {
                    return true;
                }
            }
        }

        return false;  // no cycle found from this node
    }

    // Step 1: Driver function to process the graph
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);  // adjacency list

        // Step 1.1: Convert edge list to adjacency list
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);  // because the graph is undirected
        }

        vector<int> visited(V, 0);  // Step 1.2: Visited array

        // Step 1.3: Handle disconnected components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                // If cycle is found in any component
                if (detect(i, visited, adj)) return true;
            }
        }

        return false;  // no cycles in any component
    }
};

/*
*space complexity analysis:
Adjacency List: O(V + E) where V is vertices and E is edges
Visited Array: O(V)
Queue (BFS): O(V)
----------------------------
Total           = O(V + 2E) + O(V) + O(V)
               = O(V + 2E)

* Time Complexity: O(V + E) where V is vertices and E is edges
*/

int main()
{
    Solution sol;

    // Example graph input
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3},
        {3, 4}
    };

    bool hasCycle = sol.isCycle(V, edges);

    if (hasCycle) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle found in the graph." << endl;
    }

    return 0;
}