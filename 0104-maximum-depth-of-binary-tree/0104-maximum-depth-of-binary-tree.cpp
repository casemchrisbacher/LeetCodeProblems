/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val( 0 ), left( nullptr ), right( nullptr ) {}
 *     TreeNode( int nodeVal ) : val( nodeVal ), left( nullptr ), right( nullptr ) {}
 *     TreeNode( int nodeVal, TreeNode *left, TreeNode *right ) : val( nodeVal ), left( left ), right( right ) {}
 * };
 */
class Solution {
public:
    int maxDepth( TreeNode* root ) {
        
        // When it gets past the lowest depth, end recursion
        if ( root == nullptr )
        {
            return 0;
        }
        
        // Recursively go as far down as possible
        int left_depth = maxDepth( root->left );    // Go as far down left as possible
        int right_depth = maxDepth( root->right );  // Go as far down right as possible
        
        // Return the maximum of each side, adding one for the current node
        return ( 1 + max( left_depth, right_depth ) );
                
    } // end of maxDepth
}; // end of Solution class