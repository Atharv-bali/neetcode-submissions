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
    bool comp(TreeNode* p, TreeNode* q) {
        if(q == NULL && p == NULL)
            return true;
        if(q == NULL || p == NULL)
            return false;
        if(p->val != q->val)
            return false;
        bool left = comp(p->left,q->left);
        bool right = comp(p->right,q->right);
        return left && right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node->val == subRoot->val && comp(node,subRoot))
                return true;
            if(node->left!=NULL)
                q.push(node->left);
            if(node->right!=NULL)
                q.push(node->right);
        }
        return false;
    }
};
//Time complexity: O(N^2)
//Space complexity: O(H)