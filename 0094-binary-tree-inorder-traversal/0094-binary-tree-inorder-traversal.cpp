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
    vector<int> inorderTraversal(TreeNode* root) {
         vector<int> ans;
        if(root == NULL) return ans;

        TreeNode* current, *predecessor;
        current = root;

        while(current != NULL) {
            if(current->left == NULL) {
                ans.push_back(current->val);
                current = current->right;
            }
            else {
                // get predecessor
                predecessor = current->left;
                while(predecessor->right != NULL && predecessor->right != current) {
                    predecessor = predecessor->right;
                }

                if(predecessor->right == NULL) {
                    predecessor->right = current;
                    current = current->left;
                }
                else {
                    predecessor->right = NULL;
                    ans.push_back(current->val);
                    current = current->right;
                }
            }
        }
        return ans;
        
    }
};