#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    Solution sol;
    int numIslands = sol.numIslands(grid);
    cout << "Number of islands: " << numIslands << endl;

    return 0;
}

// * dfs without visited array
// * Time Complexity: O(n*m)
/*
class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, int n, int m){
        if(i<0 || j<0 || i>=n || j>= m || grid[i][j] =='0')
            return;

        grid[i][j] ='0';

        dfs(i, j+1, grid, n, m);
        dfs(i, j-1, grid, n, m);
        dfs(i+1, j, grid, n, m);
        dfs(i-1, j, grid, n, m);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int island = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    island ++;
                    dfs(i, j, grid, n, m);
                }
            }
        }

        return island;
    }
};
*/

// * dfs with visited array
/*
class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();

        // Base case: if out of bounds, already visited, or water
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0' ||
            vis[i][j] == 1)
            return;

        vis[i][j] = 1; // Mark visited

        // Explore 4 directions
        dfs(i, j + 1, grid, vis);
        dfs(i, j - 1, grid, vis);
        dfs(i + 1, j, grid, vis);
        dfs(i - 1, j, grid, vis);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int island = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] == '1') {
                    island++;
                    dfs(i, j, grid, vis);
                }
            }
        }

        return island;
    }
};
*/

//* bfs with queue
class Solution
{
public:
    // BFS function to traverse and mark all cells of the current island
    void bfs(int row, int col, vector<vector<char>> &grid,
             vector<vector<char>> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();

        // Direction arrays for moving: up, down, left, right
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = '1'; // Mark the cell as visited

        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // Explore all 4 directions
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + dr[i];
                int ncol = c + dc[i];

                // Check for valid cell: inside bounds, land ('1'), and not visited
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                    grid[nrow][ncol] == '1' && vis[nrow][ncol] == '0')
                {

                    vis[nrow][ncol] = '1'; // Mark as visited
                    q.push({nrow, ncol});  // Add neighbor to queue
                }
            }
        }
    }

    // Main function to count the number of islands
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // Visited matrix to keep track of visited cells
        vector<vector<char>> vis(n, vector<char>(m, '0'));

        int island = 0; // Counter for islands

        // Traverse the entire grid
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // Start BFS when an unvisited land cell is found
                if (vis[i][j] == '0' && grid[i][j] == '1')
                {
                    island++;             // Found a new island
                    bfs(i, j, grid, vis); // Explore the whole island
                }
            }
        }

        return island;
    }
};
