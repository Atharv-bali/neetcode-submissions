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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return comp(p,q);
    }
};
//Time complexity: O(N)
//Space complexity: O(H)