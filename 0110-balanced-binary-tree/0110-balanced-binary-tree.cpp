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
    int dfsIsBalanced( TreeNode* pNode, bool& rIsBalanced )
    {
        if ( pNode == nullptr || !rIsBalanced ) return 0;

        int left = dfsIsBalanced( pNode->left, rIsBalanced );
        int right = dfsIsBalanced( pNode->right, rIsBalanced );

        if ( std::abs( left - right ) > 1 )
        {
            rIsBalanced = false;
        }
    
        return std::max( left, right ) + 1;
    }
public:
    bool isBalanced( TreeNode* pRoot )
    {
        bool is_balanced{ true };
        dfsIsBalanced( pRoot, is_balanced );
        return is_balanced;
    } // end of isBalanced
};