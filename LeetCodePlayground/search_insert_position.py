# https://leetcode.com/problems/search-insert-position/

from typing import List

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        low: int  = 0
        high: int = len(nums)
        mid: int  = 0

        if target > nums[high - 1]:
            return high

        while (low <= high):
            mid = (low + high)
            if (nums[mid] == target):
                return mid

            if (target < nums[mid]):
                high = mid - 1
            else:
                low = mid + 1

        return low
