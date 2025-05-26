class Solution
{
public:
    void inOrder(TreeNode *root, vector<int> &arr)
    {
        if (!root)
            return;

        inOrder(root->left, arr);
        arr.push_back(root->val);
        inOrder(root->right, arr);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> arr;
        inOrder(root, arr);
        return arr[k - 1];
    }
};