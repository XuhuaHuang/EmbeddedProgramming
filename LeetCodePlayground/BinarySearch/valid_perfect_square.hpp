// https://leetcode.com/problems/valid-perfect-square

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (num == 1 || num == 4 || num == 9 || num == 16 || num == 25)
        {
            return true;
        }
        else
        {
            int start = 0;
            int end   = num;
            while (start <= end)
            {
                long long int mid = start + (end - start) / 2;
                if (mid * mid == num)
                {
                    return true;
                }
                else if (mid * mid > num)
                {
                    end = mid - 1;
                }
                else if (mid * mid < num)
                {
                    start = mid + 1;
                }
            }
        }
        return false;
    }
};
