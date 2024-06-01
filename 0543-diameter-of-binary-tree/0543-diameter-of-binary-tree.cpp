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
    // find the max depth of the given tree - DFS
    int maxDepth( TreeNode* pNode, int& rCurMax )
    {
        if ( pNode == nullptr ) return 0;
        int left_width = maxDepth( pNode->left, rCurMax ) + 1;
        int right_width = maxDepth( pNode->right, rCurMax ) + 1;
        rCurMax = std::max( rCurMax, right_width + left_width );
        return std::max( left_width, right_width );
    } // end of maxDepth
public:
    int diameterOfBinaryTree( TreeNode* pRoot )
    {
        int cur_max{-1};
        maxDepth( pRoot, cur_max );
        return cur_max - 2;
    } // end of diameterOfBinaryTree
}; // end of Solution class