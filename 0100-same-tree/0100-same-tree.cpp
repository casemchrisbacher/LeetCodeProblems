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
    // DFS to make sure trees are the same
    bool isSameTree( TreeNode* p, TreeNode* q )
    {
        if ( p == nullptr && q == nullptr ) return true;    // both nullptr, still identical
        if ( p == nullptr || q == nullptr ) return false;   // one nullptr, not identical
        if ( p->val != q-> val ) return false;              // values don't match

        // all have to return true to match
        return isSameTree( p->right, q->right ) && isSameTree( p->left, q->left );
    } // end of isSameTree
}; // end of SOlution class