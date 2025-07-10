#include <bits/stdc++.h>
using namespace std;

/*
?🤔 Approach:
- Use BFS (Breadth-First Search) starting from all initially rotten oranges (value 2).
- Each level of BFS represents 1 minute of time.
- From each rotten orange, try to rot adjacent fresh oranges (value 1) in 4 directions.
- Track the time when each fresh orange rots and update the maximum time.

!❌ Why not DFS?
- DFS goes deep in one path and doesn't naturally track level-wise timing.
- BFS is better for shortest path / minimum time problems like this.

*⌚ Time Complexity: O(n * m)
*📦 Space Complexity: O(n * m)
*/


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        int fresh = 0;

        // Step 1: Push all initially rotten oranges and count fresh
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int maxTime = bfs(grid, vis, q, fresh);
        return fresh == 0 ? maxTime : -1;
    }

private:
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, queue<pair<pair<int, int>, int>>& q, int& fresh) {
        int n = grid.size();
        int m = grid[0].size();

        int maxTime = 0;
        int row[] = {-1, 1, 0, 0};
        int col[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;
            q.pop();

            maxTime = max(maxTime, time);

            for (int i = 0; i < 4; i++) {
                int nRow = r + row[i];
                int nCol = c + col[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                    grid[nRow][nCol] == 1 && vis[nRow][nCol] == 0) {

                    vis[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, time + 1});
                    fresh--;
                }
            }
        }

        return maxTime;
    }
};

int main() {
    Solution sol;

    // Example grid input
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = sol.orangesRotting(grid);

    cout << "Minimum time to rot all oranges: " << result << endl;

    return 0;
}
