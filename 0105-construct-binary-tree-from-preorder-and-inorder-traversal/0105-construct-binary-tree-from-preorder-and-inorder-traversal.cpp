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
    unordered_map<int, int> mp;

    TreeNode* build(vector<int>& preorder, int& idx, int left, int right) {
        if (left > right)
            return NULL;

        TreeNode* root = new TreeNode(preorder[idx++]);

        int mid = mp[root->val];

        root->left = build(preorder, idx, left, mid - 1);
        root->right = build(preorder, idx, mid + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        int idx = 0;
        return build(preorder, idx, 0, inorder.size() - 1);
    }
};