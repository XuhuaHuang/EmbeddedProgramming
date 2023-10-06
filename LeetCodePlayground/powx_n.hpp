// https://leetcode.com/problems/powx-n

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0 || x == 1.0F)
        {
            return 1.0F;
        }
        if (x == -1.0)
        {
            if (n % 2 == 0)
            {
                return 1.0F;
            }
            else
            {
                return -1.0F;
            }
        }
        if (n == -2147483648 || n == 2147483647)
        {
            return 0.0F;
        }

        double result = x;
        for (int i = 1; i < abs(n); i++)
        {
            result = result * x;
        }
        if (n > 0)
        {
            return result;
        }
        if (n < 0)
        {
            return 1 / result;
        }
        return 0.0F;
    }
};
