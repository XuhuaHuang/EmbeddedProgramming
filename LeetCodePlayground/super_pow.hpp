// https://leetcode.com/problems/super-pow

class Solution
{
    const int c = 1337;

public:
    int superPow(int a, vector<int>& b)
    {
        int r = 1;
        a %= c;
        for (int i = 0; i < b.size(); i++)
        {
            r = (powmod(r, 10) * powmod(a, b[i])) % c;
        }
        return r;
    }

private:
    inline int powmod(int r, int k)
    {
        int x = 1;
        for (int i = 1; i <= k; i++)
        {
            x = (x * r) % c;
        }
        return x;
    }
};
