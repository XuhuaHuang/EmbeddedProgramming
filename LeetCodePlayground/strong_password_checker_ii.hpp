// https://leetcode.com/problems/strong-password-checker-ii

#include <string>

class Solution
{
public:
    bool strongPasswordCheckerII(std::string password)
    {
        // check if the length is greater than 8
        if (password.size() < 8)
        {
            return false;
        }

        // check if it contains upper case, lower case and digit characters
        bool upper = false, lower = false, digit = false;
        for (auto it : password)
        {
            if (it <= 'z' && it >= 'a')
            {
                lower = true;
            }
            else if (it <= 'Z' && it >= 'A')
            {
                upper = true;
            }
            else if (it <= '9' && it >= '0')
            {
                digit = true;
            }
        }
        if (!upper || !lower || !digit)
        {
            return false;
        }

        // check for special cases
        const std::string special     = "!@#$%^&*()-+";
        bool              specialFlag = false;
        for (auto it : special)
        {
            int fnd = password.find(it);
            if (fnd >= 0)
            {
                specialFlag = true;
                break;
            }
        }
        if (!specialFlag)
        {
            return false;
        }

        // check for same two characters adjcent
        for (int i = 0; i < password.size() - 1; i++)
        {
            if (password[i] == password[i + 1])
            {
                return false;
            }
        }

        return true;
    }
};
