class Solution(object):
    def reverseOnlyLetters(self, S):
        """
        :type S: str
        :rtype: str
        """
        n = len(S)
        S = list(S)
        left, right = 0, n-1
        while left < right:
            while left < n and not S[left].isalpha():
                left += 1
            while right >= 0 and not S[right].isalpha():
                right -= 1
            if left < right:
                S[left], S[right] = S[right], S[left]
                left += 1
                right -= 1
        return ''.join(S)