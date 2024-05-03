class Solution {
public:
    bool isHappy( int n )
    {
        int one_digit{0};
        std::unordered_set<int> seen_val;

        while ( n != 1 && !seen_val.count(n) )
        {
            int sum{0};
            seen_val.insert( n );
            while ( n > 0 )
            {
                one_digit = n % 10;
                sum += ( one_digit * one_digit );
                n /= 10;
            }
            n = sum;
        }
        return ( n == 1 );
    }
};