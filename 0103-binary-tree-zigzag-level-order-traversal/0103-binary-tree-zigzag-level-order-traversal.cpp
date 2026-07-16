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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        stack<TreeNode*> currentLevel;
        stack<TreeNode*> nextLevel;
        currentLevel.push(root);
        bool leftToRight = true;
        vector<int> row;

        while(!currentLevel.empty()){
            TreeNode* node = currentLevel.top();
            currentLevel.pop();
            row.push_back(node->val);
            if(leftToRight){
                if(node->left) nextLevel.push(node->left); 
                if(node->right) nextLevel.push(node->right); 
            }else{
                if(node->right) nextLevel.push(node->right); 
                if(node->left) nextLevel.push(node->left); 
            }
            if(currentLevel.empty()){
                ans.push_back(row);
                row.clear();
                leftToRight = !leftToRight;
                swap(currentLevel, nextLevel);
            }
        }
        return ans;
    }
};