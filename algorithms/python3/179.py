from functools import cmp_to_key

class Solution:
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        nums = sorted(map(str, nums), key=cmp_to_key(self.cmp))
        return str(int(''.join(nums)))
        
    def cmp(self, x, y):
        a, b = int(x+y), int(y+x)
        if a < b:
            return 1
        elif a > b:
            return -1
        else:
            return 0
