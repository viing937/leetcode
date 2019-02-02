class Solution:
    def findIntegers(self, num):
        """
        :type num: int
        :rtype: int
        """
        cache = {'': 1, '0': 1, '1': 2}
        num = bin(num)[2:]
        self.helper(num, cache)
        return cache[num]

    def helper(self, num, cache):
        if num in cache:
            return cache[num]
        cache[num] = 0
        if num[:2] == '10':
            cache[num] += self.helper(num[2:], cache)
            cache[num] += self.helper('1'*(len(num)-1), cache)
        elif num[:2] == '11':
            cache[num] += self.helper('1'*(len(num)-2), cache)
            cache[num] += self.helper('1'*(len(num)-1), cache)
        else:
            cache[num] += self.helper(num[1:], cache)
        return cache[num]
