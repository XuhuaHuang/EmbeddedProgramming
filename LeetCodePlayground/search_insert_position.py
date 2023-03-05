# https://leetcode.com/problems/search-insert-position/

from typing import List
import unittest


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        low: int = 0
        high: int = len(nums)
        mid: int = 0

        if target > nums[high - 1]:
            return high

        while low <= high:
            mid = (low + high) // 2
            if nums[mid] == target:
                return mid

            if target < nums[mid]:
                high = mid - 1
            else:
                low = mid + 1

        return low


class TestSearchInsertPositionSolution(unittest.TestCase):

    def test_solution(self):
        nums: List[int] = [1,3,5,6]
        solution: Solution = Solution()
        # Input: nums = [1,3,5,6], target = 5
        # Output: 2
        assert(2 == solution.searchInsert(nums=nums, target=5))
        assert(1 == solution.searchInsert(nums=[1, 3, 5, 6], target=2))
        assert(4 == solution.searchInsert(nums=[1, 3, 5, 6], target=7))


if __name__ == '__main__':
    unittest.main()
