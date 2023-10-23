// https://leetcode.com/problems/reshape-the-matrix

#include <vector>

class Solution
{
    template<typename T>
    using vector = std::vector<T>;

public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c)
    {
        int m     = size(mat);
        int n     = size(mat[0]);
        int total = m * n;
        if (r * c != total)
        {
            return mat;
        }
        vector<vector<int>> ans(r, vector<int>(c));
        for (int i = 0; i < total; i++)
        {
            ans[i / c][i % c] = mat[i / n][i % n];
        }
        return ans;
    }
};
