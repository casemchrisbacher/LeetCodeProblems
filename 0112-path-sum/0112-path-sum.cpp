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
    bool hasPathSum( TreeNode* root, int targetSum ) 
    {
        // general base case, want to return false when on a null ptr
        if ( root == nullptr )
        {
            return false;
        }
        // update the targetSum value based on current node
        targetSum -= root->val;

        // Decides output of recusion - what is being checked for
        if ( root->left == nullptr && root->right == nullptr && targetSum == 0 )
        {
            return true;
        }
        
        // All the way left, all the way right - Inorder DFS
        return ( hasPathSum( root->left, targetSum ) || hasPathSum( root->right, targetSum ) );
    } // end of hasPathSum
}; // end of Solution Class