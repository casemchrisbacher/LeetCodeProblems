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
    // DFS looking for the lowest depth
    int maxDepth( TreeNode* root )
    {
        // base case
        if ( root == nullptr )
        {
            return 0;
        }
        // get to the bottom, inc return by one every time
        int left = maxDepth( root->left ) + 1;
        int right = maxDepth( root-> right ) + 1;

        return max( left, right );
    } // end of maxDepth
}; // end of Solution class