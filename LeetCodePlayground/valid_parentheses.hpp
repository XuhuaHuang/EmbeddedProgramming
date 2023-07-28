// https://leetcode.com/problems/valid-parentheses

class Solution
{
    template<typename T>
    using stack = std::stack<T>;

public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            // if opening bracket then push into the stack
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }

            else
            {
                // if a closing bracket then we compare with the top of the stack
                // while comparing with top of stack we have 2 cases
                // the stack can be empty or the stack is not empty
                if (!st.empty())
                {
                    char top = st.top();
                    if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
                    {
                        // if matches then pop
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    // if stack is empty and we get a closing bracket means the string is unbalanced
                    return false;
                }
            }
        }

        // in the end if the stack is empty -- meaning there is no opening bracket present in the stack -- meaning all
        // opening brackets have found their corresponding closing bracket and have been popped then we return trie
        if (st.empty())
        {
            return true;
        }
        return false;
    }
};
