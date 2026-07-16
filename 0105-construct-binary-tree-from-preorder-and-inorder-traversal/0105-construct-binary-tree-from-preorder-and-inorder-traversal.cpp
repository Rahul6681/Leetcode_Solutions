/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int search(vector<int>& inorder, int left, int right, int val) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == val)
                return i;
        }
        return -1;
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int& idx, int left, int right) {

        if (left > right)
            return NULL;

        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;

        int mid = search(inorder, left, right, root->val);

        root->left = build(preorder, inorder, idx, left, mid - 1);
        root->right = build(preorder, inorder, idx, mid + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return build(preorder, inorder, idx, 0, inorder.size() - 1);
    }
};