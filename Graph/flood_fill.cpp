#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int i, int j, int initialColor, int finalColor, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Base case: out of bounds or not matching initial color
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != initialColor)
            return;

        grid[i][j] = finalColor;

        // Explore 4 directions
        dfs(i, j + 1, initialColor, finalColor, grid);
        dfs(i, j - 1, initialColor, finalColor, grid);
        dfs(i + 1, j, initialColor, finalColor, grid);
        dfs(i - 1, j, initialColor, finalColor, grid);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> grid = image;
        int initialColor = image[sr][sc];

        // Important: prevent infinite loop if color is same
        if (initialColor == color)
            return image;

        dfs(sr, sc, initialColor, color, grid);
        return grid;
    }
};

int main() {
    Solution sol;
    
    // Sample image (2D grid)
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    
    int sr = 1, sc = 1; // Starting pixel
    int newColor = 2;

    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);

    cout << "Flood Filled Image:\n";
    for (const auto& row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << "\n";
    }

    return 0;
}
