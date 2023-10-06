// https://leetcode.com/problems/reverse-words-in-a-string

class Solution
{
    template<typename T>
    using stack       = std::stack<T>;

    using string      = std::string;
    using string_view = std::string_view;

public:
    static string reverseWords(const string_view s)
    {
        // Breakup the input into words and put them on a stack.
        stack<string_view> st;
        size_t             start = 0;
        size_t             end   = 0;
        while ((start = s.find_first_not_of(' ', end)) != string::npos)
        {
            end = s.find_first_of(' ', start);
            st.push(s.substr(start, end - start));
        }
        // Stitch the answer together.
        string ans;
        ans.reserve(size(s));
        while (!empty(st))
        {
            if (!empty(ans))
            {
                ans.push_back(' ');
            }
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
