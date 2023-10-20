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
    int findPosition(vector<int>& inorder, int element, int start, int end)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==element)
        {
            return i;
        }
    }
    return -1;
}

TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int n, int &postIndex, int inStart, int inEnd)
{
    // base case
    if(postIndex < 0 || inStart > inEnd)
    {
        return NULL;
    }
    
    int element=postorder[postIndex--];
    TreeNode* root=new TreeNode(element);
    int position=findPosition(inorder, element, inStart, inEnd);
    
    // Recursive Calls
    root->right=solve(inorder, postorder, n, postIndex, position+1, inEnd); 
    root->left=solve(inorder, postorder, n, postIndex, inStart, position-1);
    
    return root;

}

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n=postorder.size();
        
        int postIndex=n-1;

        TreeNode* ans=solve(inorder, postorder, n, postIndex, 0, n-1);
    
        return ans;
        
    }
};