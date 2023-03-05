# https://leetcode.com/problems/separate-the-digits-in-an-array

from typing import List
import unittest


class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        ans: List[int] = []
        for num in nums:
            tmp: str = str(num)
            for c in tmp:
                ans.append(int(c))

        return ans


class TestDigitsSeparationSolution(unittest.TestCase):

    def test_solution(self):
        nums: List[int] = [13,25,83,77]
        solution: Solution = Solution()
        assert([1,3,2,5,8,3,7,7] == solution.separateDigits(nums=nums))
        assert([7,1,3,9] == solution.separateDigits(nums=[7,1,3,9]))


if __name__ == '__main__':
    unittest.main()
