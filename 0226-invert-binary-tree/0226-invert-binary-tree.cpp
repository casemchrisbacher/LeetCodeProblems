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
    // Recursive DFS where we swap before we check the next node
    TreeNode* invertTree( TreeNode* root ) 
    {
        // base case (when to exit recursion)
        if ( root == nullptr )
        {
            return root;
        }
        
        std::swap( root->left, root->right );   // Swap the child nodes
        invertTree( root->left );   // All the way left
        invertTree( root->right );  // All the way right
        return root;
    } // end of invertTree
}; // end of Solution class