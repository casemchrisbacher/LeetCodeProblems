class Solution {
public:
    vector<vector<int>> threeSum( vector<int>& nums )
    {
        sort( nums.begin(), nums.end() );
        const int NUM_SIZE = nums.size();
        int l = 0;
        int r = NUM_SIZE - 1;
        std::vector<std::vector<int>> trips;
        std::set<std::vector<int>> set;

        for ( int ind = 0; ind < NUM_SIZE - 2; ind++ )
        {
            l = ind + 1;
            r = NUM_SIZE - 1;
            while ( l < r )
            {        
                int sum = nums[ l ] + nums[ r ] + nums[ ind ];
                
                if ( sum > 0 )
                {
                    r--;
                }
                else if ( sum < 0 )
                {
                    l++;
                }
                else
                {
                    set.insert( { nums[ l ], nums[ ind ], nums[ r ] } );
                    r--;
                    l++;
                }
            }
        }
        for ( const auto & trip : set )
        {
            trips.push_back( trip );
        }
        return trips;
    }
};