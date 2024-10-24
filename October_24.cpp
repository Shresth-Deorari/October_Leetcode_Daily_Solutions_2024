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
    bool areFlipEquivalent(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr || root2 == nullptr) 
            return root1 == root2;
        if (root1->val != root2->val) 
            return false;

        bool nonFlipped = areFlipEquivalent(root1->left, root2->left) && areFlipEquivalent(root1->right, root2->right);
        bool flipped = areFlipEquivalent(root1->left, root2->right) && areFlipEquivalent(root1->right, root2->left);
        
        return nonFlipped || flipped;
    }

public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return areFlipEquivalent(root1, root2);
    }
};
