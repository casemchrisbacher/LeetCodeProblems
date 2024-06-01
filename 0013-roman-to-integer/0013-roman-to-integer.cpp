class Solution {
public:
    int romanToInt( string s )
    {
        std::map<char,int> val{
            { 'I', 1 },
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 }
        };
        int prev_val{ 0 };
        int total{ 0 };
        for ( int ind = s.length() - 1; ind >= 0; ind-- )
        {
            if ( prev_val > val[ s[ ind ] ] )
            {
                total -= val[ s[ ind ] ];
            }
            else
            {
                total += val[ s[ ind ] ];
            }
            prev_val = val[ s[ ind ] ];
        }
        return total;
    }
};