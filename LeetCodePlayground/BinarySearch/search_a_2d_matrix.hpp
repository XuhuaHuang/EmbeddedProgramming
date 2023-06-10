/* clang-format off */
/*****************************************************************//**
 * \file   search_a_2d_matrix.hpp
 * \brief  Xuhua Huang
 * 
 * \author Xuhua Huang
 * \date   March 07, 2023
 *********************************************************************/
/* clang-format on */

// https://leetcode.com/problems/search-a-2d-matrix

class Solution
{
    template<typename T>
    using vector = std::vector<T>;

public:
    static inline bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int row   = matrix.size();
        int col   = matrix[0].size();
        int start = 0;
        int end   = (row * col) - 1;

        while (start <= end)
        {
            int mid     = (start + end) / 2;
            int element = matrix[mid / col][mid % col];

            if (element == target)
            {
                return true;
            }
            else if (element > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return false;
    }
};
