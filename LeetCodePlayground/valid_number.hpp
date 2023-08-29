// https://leetcode.com/problems/valid-number

class Solution
{
public:
    bool isNumber(string s)
    {
        /* replace all the 'E' with a lower case 'e'; O(n) */
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'E')
            {
                s[i] = 'e';
            }
        }

        /* verify that there is only one or zero decimal point */
        if (count(s.begin(), s.end(), '.'))
        {
            if (count(s.begin(), s.end(), '.') > 1)
            {
                return false;
            }
        }

        /* verify that there is only one 'e' followed by the exponent value */
        if (count(s.begin(), s.end(), 'e'))
        {
            if (count(s.begin(), s.end(), 'e') > 1)
            {
                return false;
            }
        }

        /* string has a '+' sign */
        if (count(s.begin(), s.end(), '+'))
        {
            if (count(s.begin(), s.end(), '+') == s.size())
            {
                return false;
            }
            if (count(s.begin(), s.end(), '.'))
            {
                if (s.size() == 2)
                {
                    return false;
                }
            }

            if (count(s.begin(), s.end(), '+') == 1)
            {
                if (count(s.begin(), s.end(), 'e') == 1)
                {
                    if (s[0] == '+' && s[1] == 'e')
                    {
                        return false;
                    }
                    int pos = find(s.begin(), s.end(), 'e') - s.begin();
                    if (s[pos + 1] == '+' && pos + 1 == s.size() - 1)
                    {
                        return false;
                    }
                    if (s[0] != '+' && s[pos + 1] != '+')
                    {
                        return false;
                    }
                }
                else
                {
                    if (s[0] != '+')
                    {
                        return false;
                    }
                }
            }
            else if (count(s.begin(), s.end(), '+') == 2)
            {
                if (count(s.begin(), s.end(), 'e') == 1)
                {
                    if (s[0] == '+' && s[1] == 'e')
                    {
                        return false;
                    }
                    int pos = find(s.begin(), s.end(), 'e') - s.begin();
                    if (s[pos + 1] == '+' && pos + 1 == s.size() - 1)
                    {
                        return false;
                    }
                    if (s[0] != '+' && s[pos + 1] != '+')
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        if (count(s.begin(), s.end(), '-'))
        {
            if (count(s.begin(), s.end(), '-') == s.size())
            {
                return false;
            }
            if (count(s.begin(), s.end(), '.'))
            {
                if (s.size() == 2)
                {
                    return false;
                }
            }
            if (count(s.begin(), s.end(), '-') == 1)
            {
                if (count(s.begin(), s.end(), 'e') == 1)
                {
                    if (s[0] == '-' && s[1] == 'e')
                    {
                        return false;
                    }
                    int pos = find(s.begin(), s.end(), 'e') - s.begin();
                    if (s[pos + 1] == '-' && pos + 1 == s.size() - 1)
                    {
                        return false;
                    }
                    if (s[0] != '-' && s[pos + 1] != '-')
                    {
                        return false;
                    }
                }
                else
                {
                    if (s[0] != '-')
                    {
                        return false;
                    }
                }
            }
            else if (count(s.begin(), s.end(), '-') == 2)
            {
                if (count(s.begin(), s.end(), 'e') == 1)
                {
                    if (s[0] == '-' && s[1] == 'e')
                    {
                        return false;
                    }
                    int pos = find(s.begin(), s.end(), 'e') - s.begin();
                    if (s[pos + 1] == '-' && pos + 1 == s.size() - 1)
                    {
                        return false;
                    }
                    if (s[0] != '-' && s[pos + 1] != '-')
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        if (count(s.begin(), s.end(), '+') && count(s.begin(), s.end(), '-'))
        {
            if (count(s.begin(), s.end(), '+') + count(s.begin(), s.end(), '-') == s.size())
            {
                return false;
            }
            if (count(s.begin(), s.end(), '+') == 1 && count(s.begin(), s.end(), '-') == 1)
            {
                if (count(s.begin(), s.end(), 'e') == 1)
                {
                    int pos = find(s.begin(), s.end(), 'e') - s.begin();
                    if (s[0] != '-' && s[pos + 1] != '+' && s[0] != '+' && s[pos + 1] != '-')
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        if (count(s.begin(), s.end(), 'e') && count(s.begin(), s.end(), '.'))
        {
            int p2 = find(s.begin(), s.end(), 'e') - s.begin(), p1 = find(s.begin(), s.end(), '.') - s.begin();
            if ((p2 < p1) || (p1 == 0 && p2 == 1) || (p1 == s.size() - 2 && p2 == s.size() - 1))
            {
                return false;
            }
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != 'e' && s[i] != '+' && s[i] != '-' && (s[i] < 48 || s[i] > 57) && s[i] != '.')
            {
                return false;
            }
            if (s[i] == 'e' && (i == s.size() - 1 || i == 0))
            {
                return false;
            }
            if (s[i] == '.' && (i == s.size() - 1 && i == 0))
            {
                return false;
            }
        }

        return true;
    }
};
