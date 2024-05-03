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
    // DFS helper function
    void depthFirstSearch( TreeNode* root, std::vector<int>& rInOrder )
    {
        // base condition (when to end recusion)
        if ( root == nullptr )
        {
            return; // end recusion when it gets past a valid nde
        }
        depthFirstSearch( root->left, rInOrder );   // all the way left
        rInOrder.push_back( root->val );            // read the values
        depthFirstSearch( root->right, rInOrder );  // all the way right
    } // end of depthFirstSearch
public:
    // Recursive approach
    vector<int> inorderTraversal( TreeNode* root ) 
    {
        std::vector<int> in_order;
        depthFirstSearch( root, in_order ); // call helper
        return in_order;
    } // end of inorderTraversal

}; // end of Solution class