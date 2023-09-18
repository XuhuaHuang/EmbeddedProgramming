// https://leetcode.com/problems/valid-palindrome

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string str = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (isalnum(s[i]))
            {
                str += tolower(s[i]);
            }
            else
            {
                continue;
            }
            
        }
        string copy = str;
        reverse(str.begin(), str.end());
        int i = 0;
        int j = 0;
        while (i < str.size() && j < copy.size())
        {
            if (str[i] != copy[j])
            {
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};
