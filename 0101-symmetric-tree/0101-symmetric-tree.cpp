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
    // DFS of both sides of the tree, comparing at each node
    bool doubleDfs( TreeNode* pLeftSide, TreeNode* pRightSide )
    {
        // Base case if they're both null
        if ( pLeftSide == nullptr && pRightSide == nullptr )
        {
            return true;
        }
        // Alternative base case if one is null, tree isn't symetrical
        if ( pLeftSide == nullptr || pRightSide == nullptr )
        {
            return false;
        }
        // If they're not equal return false
        if ( pLeftSide->val != pRightSide->val )
        {
            return false;
        }
        // Recursively call function, Inorder and Postorder
        return doubleDfs( pLeftSide->left, pRightSide->right ) && doubleDfs( pLeftSide->right, pRightSide->left );
    } // end of doubleDfs
public:
    // Default function for problem - just calls my helper function
    bool isSymmetric( TreeNode* root )
    {
        return doubleDfs( root->left, root->right );
    } // end of is Symmetric
}; // end of Solution class