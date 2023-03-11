# https://leetcode.com/problems/maximum-subarray


from math import inf
from typing import List
import unittest


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        cur_max: int = 0
        max_till_now: float = -inf
        for c in nums:
            cur_max = max(c, cur_max + c)
            max_till_now = max(max_till_now, cur_max)
        return int(max_till_now)


class TestMaxSubArraySolution(unittest.TestCase):

    def test_solution(self):
        nums: List[int] = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
        solution: Solution = Solution()
        # [4, -1, 2, 1]
        assert(6 == solution.maxSubArray(nums=nums))


if __name__ == '__main__':
    unittest.main()
