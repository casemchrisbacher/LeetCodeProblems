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
    // DFS to find the max depth of a binary tree
    int maxDepth( TreeNode* pNode ) {
        if ( pNode == nullptr ) return 0;    // base case

        int left = maxDepth( pNode->left ) + 1;
        int right = maxDepth( pNode->right ) + 1;

        return std::max( left, right );
    } // end of maxDepth
}; // end of Solution class