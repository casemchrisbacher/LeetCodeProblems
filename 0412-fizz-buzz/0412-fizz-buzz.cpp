class Solution {
public:
    vector<string> fizzBuzz( int n ) {
        vector<std::string> fizz_buzz;  // output vector
        
        // loop from zero -> n, adding strings to vector as we go
        for ( int num_ind = 1; num_ind <= n; num_ind++ )
        {
            // Check if divisible by 15 (3 and 5) - Push Back "FizzBuzz"
            if ( num_ind % 15 == 0 )
            {
                fizz_buzz.push_back( "FizzBuzz" );
            }
            // Check if divisible by 3 - Push Back "Fizz"
            else if ( num_ind % 3 == 0 )
            {
                fizz_buzz.push_back( "Fizz" );
            }
            // Check if divisible by 5 - Push Back "Buzz"
            else if ( num_ind % 5 == 0 )
            {
                fizz_buzz.push_back( "Buzz" );
            }
            // Not Divisible by any of them 
            else
            {
                fizz_buzz.push_back( std::to_string( num_ind ) );
            }
        }
        return fizz_buzz;
    } // end of fizzBuzz
}; // end of Solution class