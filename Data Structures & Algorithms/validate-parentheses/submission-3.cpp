class Solution {
public:
    bool isValid(string s)
    {
        stack<char> stk;

        for (auto& c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                stk.push(c);
            }
            else // c is a closing bracket
            {
                if (stk.empty())
                    return false;  // nothing to match against

                if ((c == ')' && stk.top() == '(') ||
                    (c == ']' && stk.top() == '[') ||
                    (c == '}' && stk.top() == '{'))
                    stk.pop();
                else
                    return false;  // mismatched pair
            }
        }
        return stk.empty();
    }
};