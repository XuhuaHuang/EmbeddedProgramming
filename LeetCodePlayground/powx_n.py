# https://leetcode.com/problems/powx-n

class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0 or x == 1.0:
            return 1.0
        if x == -1.0:
            if n % 2 == 0:
                return 1.0
            else:
                return -1.0
        if n == -2147483648 or n == 2147483647:
            return 0.0

        result: float = x
        i: int = 1
        while i < abs(n):
            result = result * x
            i += 1
        if n > 0:
            return result
        elif n < 0:
            return 1 / result
        return 0.0
