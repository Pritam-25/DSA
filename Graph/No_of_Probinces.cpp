#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adjLs, vector<int> &vis)
    {
        vis[node] = 1;
        for (auto it : adjLs[node])
        {
            if (!vis[it])
            {
                dfs(it, adjLs, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int V = isConnected.size();
        vector<vector<int>> adjLs(V);

        // convert adj matrix to adj list
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        vector<int> vis(V, 0);
        int count = 0;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                count++;
                dfs(i, adjLs, vis);
            }
        }

        return count;
    }
};

int main()
{
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}};
    Solution sol;
    int result = sol.findCircleNum(isConnected);
    cout << "Number of provinces: " << result << endl;
    return 0;
}