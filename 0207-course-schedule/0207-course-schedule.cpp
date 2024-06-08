class Solution {
public:
    bool canFinish( int numCourses, vector<vector<int>>& prerequisites )
    {
        std::vector<int> in_deg( numCourses, 0 );
        std::vector<std::vector<int>> adj( numCourses, std::vector<int>() );
        for ( const std::vector<int>& pre_pair : prerequisites )
        {
            adj[ pre_pair[ 1 ] ].push_back( pre_pair[ 0 ] );
            in_deg[ pre_pair[ 0 ] ]++;
        }

        std::queue<int> q;
        for ( int class_ind = 0; class_ind < numCourses; class_ind++ )
        {
            if ( in_deg[ class_ind ] == 0 )
            {
                q.push( class_ind );
            }
        }

        int sorted{ 0 };
        while ( !q.empty() )
        {
            int cur_ind = q.front();
            q.pop();
            std::cout<< cur_ind << " ";
            sorted++;
            for ( const auto& adj_num : adj[ cur_ind ] )
            {
                in_deg[ adj_num ]--;
                if ( in_deg[ adj_num ] == 0 )
                {
                    q.push( adj_num );
                }
            }

        }
        return ( sorted == numCourses );
    }   
};