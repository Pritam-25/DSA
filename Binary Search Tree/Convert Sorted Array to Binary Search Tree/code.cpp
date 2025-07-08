#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int main()
{
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution sol;
    TreeNode *root = sol.sortedArrayToBST(nums);
    return 0;
}

class Solution
{
public:
    TreeNode *buildBST(vector<int> &nums, int low, int high)
    {
        if (low > high)
            return nullptr;

        int mid = (low + high) / 2;
        TreeNode *root = new TreeNode(nums[mid]);

        root->left = buildBST(nums, low, mid - 1);
        root->right = buildBST(nums, mid + 1, high);

        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return buildBST(nums, 0, nums.size() - 1);
    }
};