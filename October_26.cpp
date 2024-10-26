/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    unordered_map<int, int> nodeHeight; 
    unordered_map<int, int> nodeLevel;  
    vector<vector<int>> levelHeights;  
    int calculateHeight(TreeNode* node, int level) {
        if (!node) return -1;

        nodeLevel[node->val] = level;

        int leftHeight = calculateHeight(node->left, level + 1);
        int rightHeight = calculateHeight(node->right, level + 1);
        int height = max(leftHeight, rightHeight) + 1;
        nodeHeight[node->val] = height;

        if (levelHeights.size() <= level) levelHeights.resize(level + 1);

        levelHeights[level].push_back(height);
        if (levelHeights[level].size() > 2) {
            nth_element(levelHeights[level].begin(), levelHeights[level].begin() + 2, levelHeights[level].end(), greater<int>());
            levelHeights[level].resize(2);
        }

        return height;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        calculateHeight(root, 0);
        vector<int> result;
        for (int query : queries) {
            int level = nodeLevel[query];
            int originalHeight = nodeHeight[query];

            if (levelHeights[level].size() == 1) {
                result.push_back(level - 1);
            } else {
                int maxHeightWithoutNode = (levelHeights[level][0] == originalHeight) ? levelHeights[level][1] : levelHeights[level][0];
                result.push_back(level + maxHeightWithoutNode);
            }
        }
        return result;
    }
};
