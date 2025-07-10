#include <bits/stdc++.h>
using namespace std;

/*
?🤔 Approach:
- Multi-source BFS: start from all 0's.
- Push all 0's into the queue with distance 0.
- BFS from all 0's to update the nearest distance for each 1.

*⌚ Time: O(N*M)
*📦 Space: O(N*M)
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));  // initialize with 0

        queue<pair<pair<int, int>, int>> q; //  {{i, j}, distance}

        // Step 1: Push all 0's into the queue with distance 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};

        // Step 2: BFS to find the nearest 0 for each cell
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();

            dist[row][col] = step;  // ✅ correct place to set distance

            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                    vis[nRow][nCol] == 0) {

                    vis[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, step + 1});
                }
            }
        }

        return dist;
    }
};

int main()
{
    Solution sol;

    // Example input
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    vector<vector<int>> result = sol.updateMatrix(mat);

    // Print the result
    for (const auto& row : result) {
        for (int dist : row) {
            cout << dist << " ";
        }
        cout << endl;
    }

    return 0;
}