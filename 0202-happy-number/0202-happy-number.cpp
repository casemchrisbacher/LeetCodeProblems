class Solution {
public:
    bool isHappy( int n )
    {
        int one_digit{0};                   // end digit of number
        std::unordered_set<int> seen_val;   // marks values as seen to prevent loop

        // end conditions given in problem - ( n == 1), starts looping
        while ( n != 1 && !seen_val.count(n) )
        {
            int sum{0};             // sum of the current set
            seen_val.insert( n );   // insert value as seen
            while ( n > 0 )
            {
                one_digit = n % 10;
                sum += ( one_digit * one_digit );
                n /= 10;
            }
            n = sum;
        }
        return ( n == 1 );  // true if happy number, false otherwise
    }
};