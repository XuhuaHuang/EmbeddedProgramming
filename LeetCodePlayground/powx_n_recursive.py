# https://leetcode.com/problems/powx-n


class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        elif n == -1:
            return 1 / x
        else:
            nums = self.myPow(x, n // 2)
            res = nums * nums
            if n % 2 == 1:
                res *= x
            return res
