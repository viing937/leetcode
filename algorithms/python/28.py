class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if not needle: return 0
        n = len(needle)
        for i in range(0, len(haystack)-n+1):
            if haystack[i:i+n] == needle:
                return i
        return -1
