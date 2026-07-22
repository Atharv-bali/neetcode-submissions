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
    int solve(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left_height = solve(root->left);
        int right_height = solve(root->right);
        return max(left_height,right_height) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int left_dia = diameterOfBinaryTree(root->left);
        int right_dia = diameterOfBinaryTree(root->right);
        int height = solve(root->left) + solve(root->right);
        return max(left_dia,max(right_dia,height));
    }
};
//Time complexity: O(N^2)
//Space complexity: O(H)