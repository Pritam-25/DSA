class Solution
{
public:
    void findMin(TreeNode *root, int &prev, int &mini)
    {
        if (!root)
            return;

        findMin(root->left, prev, mini);
        if (prev != INT_MIN)
            mini = min(root->val - prev, mini);
        prev = root->val;
        findMin(root->right, prev, mini);
    }

    int minDiffInBST(TreeNode *root)
    {
        int prev = INT_MIN;
        int minimum = INT_MAX;

        findMin(root, prev, minimum);
        return minimum;
    }
};