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
private:
    // Input left and right side of tree, check if they're the same
    bool isSymDfs( TreeNode* pNode1, TreeNode* pNode2 )
    {
        if ( pNode1 == nullptr && pNode2 == nullptr ) return true;  // both null, still symmetric
        if ( pNode1 == nullptr || pNode2 == nullptr ) return false; // one is null - not sym
        if ( pNode1->val != pNode2->val ) return false;             // different values, not sym

        return ( isSymDfs( pNode1->left, pNode2->right ) && isSymDfs( pNode1->right, pNode2->left ) );
    } // end of is SymDfs
public:
    // Determine if binary tree is symmetric
    bool isSymmetric( TreeNode* root )
    {
        return isSymDfs( root->left, root->right );
    } // end of isSymmetric
}; // end of Solution class