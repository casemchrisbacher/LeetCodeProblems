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
    vector<int> rightSideView(TreeNode* root) 
    {
        // Edge case for BFS
        if ( root == nullptr )
        {
            return {};
        }
        vector<int> far_right;  // output vector
        queue<TreeNode*> q;     // bfs Queue
        q.push( root );         // push back the root
        
        // standard bfs
        while ( !q.empty() )
        {
            int q_size = q.size();  // queue size, changes throughout for loop
            int last_val{0};        // last val loop sets this to is the far right
            for ( int level_ind = 0; level_ind < q_size; level_ind++ )
            {
                TreeNode* cur_node = q.front();
                q.pop();
                last_val = cur_node->val;

                if ( cur_node->left != nullptr )
                {
                    q.push( cur_node->left );
                }
                if ( cur_node->right != nullptr )
                {
                    q.push( cur_node->right );
                }
            }
            far_right.push_back( last_val );
        }
        return far_right;
        
    } // end of rightSideView
}; // end of Solution Class