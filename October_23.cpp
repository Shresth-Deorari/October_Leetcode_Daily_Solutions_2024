class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root == nullptr) return root;

        queue<TreeNode*> q;
        vector<int> levelSum; 
        vector<int> sumChild;  
        sumChild.push_back(root->val);

        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            int currLevelSum = 0;
            vector<int> currSumChild;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                currLevelSum += node->val;
                int temp = 0;

                if (node->left) temp += node->left->val;
                if (node->right) temp += node->right->val;

                if (node->left){
                    q.push(node->left);
                    currSumChild.push_back(temp);
                }
                if (node->right) {
                    q.push(node->right);
                    currSumChild.push_back(temp);
                }
            }

            levelSum.push_back(currLevelSum);
            sumChild.insert(sumChild.end(), currSumChild.begin(), currSumChild.end());
        }
        q.push(root);
        int idx = 0;
        int level = 0; 

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                node->val = levelSum[level] - sumChild[idx++];

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ++level;
        }

        return root;
    }
};
