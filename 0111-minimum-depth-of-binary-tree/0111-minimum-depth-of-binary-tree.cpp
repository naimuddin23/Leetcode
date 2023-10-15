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
    int minDepth(TreeNode* root) {
        
         if(root==NULL) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        while(1){
           TreeNode* temp= q.front().first;
            int lev= q.front().second;
            q.pop();
            if(temp->left==NULL && temp->right==NULL) return lev;
            else{
                if(temp->left!=NULL){
                    q.push({temp->left,lev+1});
                    
                }
                if(temp->right!=NULL){
                    q.push({temp->right,lev+1});
                }
            }
        }
        return 1;
    }
};