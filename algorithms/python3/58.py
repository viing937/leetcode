class Solution:
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        last = s.strip().split(' ')[-1]
        return len(last)
