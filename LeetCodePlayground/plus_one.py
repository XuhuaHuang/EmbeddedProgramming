# https://leetcode.com/problems/plus-one

from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits = digits[::-1]
        x = 1
        ans = []
        for i in range(len(digits)):
            ans += [(digits[i] + x) % 10]
            x = (digits[i] + x) // 10
        if x:
            ans += [x]
        return ans[::-1]
