class Solution {
public:
    bool isValid(string s) 
    {
        std::stack<char> char_stack;

        for ( const char letter : s )
        {
            switch ( letter )
            {
                case '(':
                    char_stack.push(')');
                    break;
                case '{':
                    char_stack.push('}');
                    break;
                case '[':
                    char_stack.push(']');
                    break;
                default:
                    if ( char_stack.empty() || letter != char_stack.top() ) return false;
                    char_stack.pop();
            }
        }
        return char_stack.empty();
    }
};